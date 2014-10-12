What is whizzywig?
----------------
- Very fast and smallest WYSIWYG editor
- Cross browser support
- Built in File Browser! Browse, Insert, Delete, Renama File and create sub-folder
- Built in Image operation: Resize image


Installation:
-------------
IMPORTANT! Whizzywig now uses original Whizzywig library, then you must download it.

Installation instructions:
1. Extract to sites/all/module/whizzywig/
2. Download whizzyig61.js and whizzybrowse3.php from http://code.google.com/p/whizzywig/ and 
   put into sites/all/libraries/whizzywig/
3. Enable the whizzywig module in Drupal (admin/build/modules).
   

Configuration:
--------------
Go to Administer - Site Configuration - whizzywig

Tips:
-----
1. If you need to separate teaser and body then please install excerpt module (http://drupal.org/project/excerpt/)

2. You may add this CSS code to show Pointer on the table header for column sorting:
   table.sortable thead th {
     cursor:pointer;
   }
