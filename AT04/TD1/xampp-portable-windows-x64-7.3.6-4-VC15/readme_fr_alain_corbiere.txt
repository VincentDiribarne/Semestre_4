Le 21/07/2020, ajout de (problème des accents)
+ 	// UTF-8 conversion of Apache server configuration files 
+ 	$content=file_get_contents($confhttpdroot);
+ 	file_put_contents($confhttpdroot, utf8_encode($content));
+ 	$path_confhttpdroot = pathinfo($confhttpdroot);
+ 	$path_extra = $path_confhttpdroot['dirname']."\\extra";
+ 	$openDir_extra = opendir ($path_extra) ;
+ 	while ($res = readdir($openDir_extra)) {
+ 		if ($res != "." && $res != "..") {
+ 			$content=file_get_contents($path_extra."\\".$res);
+ 			file_put_contents($path_extra."\\".$res, utf8_encode($content));
+ 		}
+ 	}
dans install\install.php

Le 09/07/2019, ajout de
+ @if exist install\install.sys del install\install.sys 
+ @xcopy install\original . /E /Y > NUL 
dans setup_xamp.bat

Le 21/07/2019, ajout de
- apache\bin\pv -f -k mysqld.exe -q
+ rem apache\bin\pv -f -k mysqld.exe -q
+ taskkill /IM "mysqld.exe" /F
dans mysql_stop.bat