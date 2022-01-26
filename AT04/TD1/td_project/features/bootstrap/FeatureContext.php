<?php

use Behat\MinkExtension\Context\MinkContext,
    Behat\Behat\Tester\Exception\PendingException;
use Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode;

/**
 * Features context.
 */
class FeatureContext extends MinkContext
{

    /**
      * @Given /^I wait for "([^"]*)" s$/
      */
    public function iWait($seconds)
    {
		if ($this->running_javascript()) {
			$this->getSession()->wait(1000*$seconds);
		}
    }
	
    /**
      * @Given /^I upload a product image$/
      */
    public function iUploadProductImage()
    {
		$window_main_name = "main_window";
		$window_upload_name = "upload_window";
		$script = "window.name = '" . $window_main_name . "'";
		$this->getSession()->executeScript($script);
		$e = $this->getSession()->getPage()->find("css", "a#set-post-thumbnail");
		$this->getSession()->executeScript("window.open('".$e->getAttribute("href")."','".$window_upload_name."')");
		$this->getSession()->switchToWindow($window_upload_name) ;
		$this->getSession()->wait(1000);
		if ($this->getSession()->getPage()->find("css", "a:contains('browser uploader')")->isVisible())
			$this->getSession()->getPage()->find("css", "a:contains('browser uploader')")->click();
		$this->getSession()->getPage()->attachFileToField("async-upload",__DIR__.DIRECTORY_SEPARATOR."produit.jpg") ;
		$this->getSession()->wait(1000);
		$this->getSession()->getPage()->find("css", "input#html-upload")->click();
		$this->getSession()->wait(1000);
		$this->getSession()->getPage()->find("css", "a:contains('Use as product image')")->click();
		$this->getSession()->wait(1000);
		$this->getSession()->switchToWindow($window_main_name) ;
		$this->getSession()->executeScript("window.open('', '".$window_upload_name."').close()") ;
		$this->getSession()->wait(4000);
    }
	
    /**
      * @When /^I click on "(?P<element_string>(?:[^"]|\\")*)" "(?P<selector_string>[^"]*)"$/
      * @param string $element Element we look for
      * @param string $selectortype The type of what we look for
      */
    public function i_click_on($element, $selectortype)
    {
		$e = $this->getSession()->getPage()->find($selectortype, $element);
        $e->click();
    }
	
    /**
      * @When /^I press on "(?P<element_string>(?:[^"]|\\")*)" "(?P<selector_string>[^"]*)"$/
      * @param string $element Element we look for
      * @param string $selectortype The type of what we look for
      */
    public function i_press_on($element, $selectortype)
    {
		$e = $this->getSession()->getPage()->find($selectortype, $element);
        $e->press();
    }
	
    /**
      * @When /^I check on "(?P<element_string>(?:[^"]|\\")*)" "(?P<selector_string>[^"]*)"$/
      * @param string $element Element we look for
      * @param string $selectortype The type of what we look for
      */
    public function i_check_on($element, $selectortype)
    {
		$e = $this->getSession()->getPage()->find($selectortype, $element);
        $e->check();
    }
	
    /**
      * @When /^I change window size to "([^"]*)" x "([^"]*)"$/
      */
    public function i_change_window_size($width, $height)
    {
		$this->getSession()->resizeWindow((int)$width, (int)$height, 'current');
    }
	
    /**
     * Returns whether the scenario is running in a browser that can run Javascript or not.
     *
     * @return boolean
     */
    protected function running_javascript() {
        return get_class($this->getSession()->getDriver()) !== 'Behat\Mink\Driver\GoutteDriver';
    }
	
	
    /**
     * @Transform /^random@random.random$/
     * Generate a "random" alpha-numeric string.
     * @return string
     */
    public function random()
    {
        $length = 6 ;
        $pool = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
        $str = substr(str_shuffle(str_repeat($pool, $length)), 0, $length);
        return $str."@".$str.".".$str ;
    }
	
    /**
     * @Transform /^product name$/
     * Generate a "name product" with user name.
     * @return string
     */
    public function titleProduct()
    {
        return "product name (".trim(shell_exec("echo %username%")).")" ;
    }
}

