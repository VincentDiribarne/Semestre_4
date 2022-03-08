# features/woocommerce.feature
Feature: Order a product
  In order to order a product
  As a guest
  I need to select a product and to add to cart

  @javascript
  Scenario: Order one product on WooCommerce
    Given I am on "https://themes.woocommerce.com/canvas/shop"
    And I follow "Flying Ninja"
    And I wait for "1" s
    And I press "add-to-cart"

    And I click on "div.woocommerce-message a" "css"
    And I follow "Proceed to checkout"
    And I fill in "billing_email" with "random@random.random"
    And I fill in "billing_first_name" with "random"
    And I fill in "billing_last_name" with "random"
    And I select "France" from "billing_country"
    And I fill in "billing_address_1" with "33 rue du prochain jeu"
    And I fill in "billing_city" with "Laval"
    And I fill in "billing_postcode" with "53000"
    And I fill in "billing_phone" with "0102030405"
    And I fill in "account_password" with "random"
    When I press "Place order"
    And I wait for "5" s
    #...
    Then I should see "Order Received"
    #...