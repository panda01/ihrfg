<?php
// $Id: whizzywig.settings.inc,v 1.16.2.5 2010/11/09 06:08:42 thenicespider Exp $

/**
 * @file
 * Settings page callback file for the whizzywig module.
 */

/**
 * Menu callback;
 */
function whizzywig_admin_settings() {
  $form = array();
  
  // Generate the form - settings applying to all patterns first
  $form['whizzywig_general'] = array(
  '#type' => 'fieldset',
  '#title' => t('General settings'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  );
  $form['whizzywig_general']['whizzywig_xhtml'] = array(
  '#type' => 'checkbox',
  '#title' => t('Use xHTML markup'),
  '#default_value' => variable_get("whizzywig_xhtml", '0'),
  '#description' => t('Choose whether xhtml markup should be enabled or not.'),
  );
  $form['whizzywig_general']['whizzywig_editor_width'] = array(
  '#type' => 'textfield',
  '#title' => t('Editor width'),
  '#default_value' => variable_get('whizzywig_editor_width', '100%'),
  '#description' => t("Width of the whizzywig editor (%,px,em), i.e: 520px"),
  );  
  $form['whizzywig_general']['whizzywig_editor_height'] = array(
  '#type' => 'textfield',
  '#title' => t('Editor height'),
  '#default_value' => variable_get('whizzywig_editor_height', 0),
  '#description' => t("Height of the whizzywig editor (%,px,em,ex)"),
  );
  
  $form['whizzywig_general']['whizzywig_style'] = array(
  '#type' => 'radios',
  '#title' => t('CSS file for editor'),
  '#default_value' => variable_get('whizzywig_style', 1),
  '#options' => array(
  t("Use css from current theme"),
  t("Use this css file:")),
  );

  $form['whizzywig_general']['whizzywig_style_val'] = array(
  '#type' => 'textfield',
  '#default_value' => variable_get('whizzywig_style_val', 'simple.css'),
  '#description' => t("Specify the file name of your css file, css file should put to here: /sites/all/default/modules/whizzywig/css/your_css_file.css"),
  );

  $form['whizzywig_general']['whizzywig_library'] = array(
  '#type' => 'textfield',
  '#title' => t('Whizzywig library file'),
  '#default_value' => variable_get('whizzywig_library', 'whizzywig61.js'),
  '#description' => t("This module provides several version of Whizzywig library, switch only to other version if you have trouble with the default version. Note: this module working fine and tested using whizzywig61.<br />Suggested version: whizzywig58.js and whizzywig61.js "),
  );
  
  $form['whizzywig_toolbar'] = array(
  '#type' => 'fieldset',
  '#title' => t('Toolbar buttons'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
  );
  
	 $form['whizzywig_toolbar']['whizzywig_toolbar_admin'] = array(
  '#type' => 'select',
  '#title' => t('Toolbar for admin (uid=1)'),
	'#options' => array('full','basic','medium','custom'),
  '#default_value' => variable_get('whizzywig_toolbar_admin', 0),
	'#description' => t("Full-toolbar does not include custom buttons.")
  );
	
  $form['whizzywig_toolbar']['whizzywig_toolbar_basic'] = array(
  '#type' => 'textarea',
  '#title' => t('Toolbar buttons - Basic'),
  '#default_value' => variable_get('whizzywig_toolbar_basic', 'bold italic underline | left center right | number bullet indent outdent | rule link')
  );
  
  $form['whizzywig_toolbar']['whizzywig_toolbar_medium'] = array(
  '#type' => 'textarea',
  '#title' => t('Toolbar buttons - Medium'),
  '#default_value' => variable_get('whizzywig_toolbar_medium', 'bold italic underline | left center right newline number bullet indent outdent | rule link clean')
  );
  
	$custom_toolbar =
	 "bold italic underline | left center right\r\n"
   ."number bullet indent outdent | rule link table clean html superscript selectall code textbox";
	
	$complete_buttons =
	 'formatblock fontname fontsize | bold italic underline | left center right justify | number bullet indent outdent | undo redo | color hilite rule | link image table | clean html spellcheck fullscreen | tstart add_row_above add_row_below delete_row | add_column_before add_column_after delete_column | table_in_cell'; 

  $form['whizzywig_toolbar']['whizzywig_toolbar_custom'] = array(
  '#type' => 'textarea',
  '#title' => t('Toolbar buttons - Custom'),
  '#default_value' => variable_get('whizzywig_toolbar_custom',$custom_toolbar),
  '#description' => t("
	  <ol>
		<li>Complete buttons: $complete_buttons</li>
    <li>Newline: use 'newline' to make a new toolbar line or just press 'Enter'</li>
    </ol>")
  ); 
  
	$form['whizzywig_custom'] = array(
  '#type' => 'fieldset',
  '#title' => t('Custom buttons'),
  '#collapsible' => TRUE,
  '#collapsed' => TRUE,
  );
  
	$custom_buttons =
    "buts = 'selectall superscript code';\n"
   ."dobut['superscript'] = '<sup>';\n"
	 ."dobut['selectall']   = 'js:oW.document.execCommand(\"selectall\",false,\"\");';\n"
	 ."dobut['code'] = '<code>';\n\n"
	 ."sels = 'textbox';\n"
	 ."opts['textbox'] = new Array('Text box', 'Right', 'Left');\n"
	 ."vals['textbox'] = new Array(\"\",\"<div style='float:right;width:200px;border:1px solid;padding:.5em;margin:0 5px;'>#\",\"<div style='float:left;width:200px;border:1px solid;padding:.5em;margin:0 5px;'>#\");\n"
	 ; 
	  
  $form['whizzywig_custom']['whizzywig_custom_buttons'] = array(
  '#type' => 'textarea',
  '#title' => t('Custom buttons'),
  '#default_value' => variable_get('whizzywig_custom_buttons',$custom_buttons)
  );

  return system_settings_form($form);
}

function whizzywig_settings_visibility() {
  //$form = array();
   
  $form['whizzywig_visibility'] = array(
  '#type' => 'fieldset',
  '#title' => t('Visibility settings'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  );
  $form['whizzywig_visibility']['whizzywig_textarea_id'] = array(
  '#type' => 'radios',
  '#title' => t('Textarea ID'),
  '#default_value' => variable_get('whizzywig_textarea_id', 1),
  '#options' => array(
  t("Don't show whizzywig editor on this textareas ID:"),
  t("Only show whizzywig editor on this textareas ID:")),
  );
  $form['whizzywig_visibility']['whizzywig_textarea_id_val'] = array(
  '#type' => 'textarea',
  '#default_value' => variable_get('whizzywig_textarea_id_val', 'edit-teaser,edit-body'),
  '#description' => t("Specify the textarea IDs for this rule. Separate by comma."),
  );
  
  $form['whizzywig_visibility']['whizzywig_content_type'] = array(
  '#type' => 'radios',
  '#title' => t('Content type'),
  '#default_value' => variable_get('whizzywig_content_type', 1),
  '#options' => array(
  t("Don't show whizzywig editor on this content type:"),
  t("Only show whizzywig editor on this content type:")),
  );
  $form['whizzywig_visibility']['whizzywig_content_type_val'] = array(
  '#type' => 'textarea',
  '#default_value' => variable_get('whizzywig_content_type_val', 'page'),
  '#description' => t("Specify the content type for this rule. Separate by comma."),
  );   
  
  $form['whizzywig_visibility']['whizzywig_comment'] = array(
  '#type' => 'checkbox',
  '#title' => t('Enable editor for Comment'),
  '#default_value' => variable_get('whizzywig_comment', 0)
  );
  
	$form['whizzywig_visibility']['whizzywig_block'] = array(
  '#type' => 'checkbox',
  '#title' => t('Enable editor for Block'),
  '#default_value' => variable_get("whizzywig_block", 0)
  );
	
	$form['whizzywig_visibility']['whizzywig_uncollapsed'] = array(
  '#type' => 'textarea',
  '#title' => t('Set fieldset to un-collapsed for these fieldset-ids'),
  '#default_value' => variable_get("whizzywig_uncollapsed", ''),
	'#description' => t("Whizzywig has problem within collapsible fieldset. Whizzywig works fine when fieldset set to un-collapsed, this is a temporary workaround. Separate each fieldset ids with comma.")
  );
	
  $form['whizzywig_visibility']['whizzywig_page'] = array(
  '#type' => 'radios',
  '#title' => t('Show editor on specific pages'),
  '#default_value' => variable_get('whizzywig_page', 0),
  '#options' => array(
  t("Show on every page except the listed pages."),
  t("Show on only the listed pages."),
	t("Show if the following PHP code returns TRUE (PHP-mode, experts only).")),
  );
  $form['whizzywig_visibility']['whizzywig_page_val'] = array(
  '#type' => 'textarea',
  '#default_value' => variable_get('whizzywig_page_val', ''),
  '#description' => t("Enter one page per line as Drupal paths. The '*' character is a wildcard. Example paths are blog for the blog page and blog/* for every personal blog. <front> is the front page. If the PHP-mode is chosen, enter PHP code between <?php ?>. Note that executing incorrect PHP-code can break your Drupal site."),
  );
  
	return system_settings_form($form);
}

function whizzywig_settings_file_browser() {
  //$form = array();
  $form['whizzywig_file_browser'] = array(
  '#type' => 'fieldset',
  '#title' => t('File Browser'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  );
  
	$form['whizzywig_file_browser']['whizzywig_file_browser_type'] = array(
  '#type' => 'select',
  '#title' => t('File browser type'),
	'#options' => array('original','modified'),
  '#default_value' => variable_get('whizzywig_file_browser_type', 1)
  );  
	
  $form['whizzywig_file_browser']['whizzywig_folder_format'] = array(
  '#type' => 'textfield',
  '#title' => t('Folder format for each users'),
  '#default_value' => variable_get('whizzywig_folder_format', 'u[uid]'),
  '#description' => t("<ul><li>Specify the format for user folder, if you enter 'u[uid]' then the user folder become files/u1, files/u2, files/u3, etc.</li>".
	"<li>Available variables: <b>[uid]</b> = User ID, <b>[username]</b> = Username, <b>[domainname]</b> = Domain Name</li>".
	"<li>For Drupal multisite please use [domainname]-[username] to avoid conflict for same Username in different site.</li></ul>"),
  );
  $form['whizzywig_file_browser']['whizzywig_predefine_folder'] = array(
  '#type' => 'textfield',
  '#title' => t('Predefine folder for each users'),
  '#default_value' => variable_get('whizzywig_predefine_folder', ''),
  '#description' => t("Specify the predefine folder, i.e: if you enter 'article,story'' then this module will automatically create 'article and story' folder for each users, i.e: files/u1/article and files/u1/story"),
  );  
  
  $form['whizzywig_file_upload'] = array(
  '#type' => 'fieldset',
  '#title' => t('File Upload'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  );
	$form['whizzywig_file_upload']['whizzywig_file_extension'] = array(
  '#type' => 'textfield',
  '#title' => t('Allowed upload file extensions'),
  '#default_value' => variable_get('whizzywig_file_extension', 'gif jpg jpeg png'),
  '#description' => t("Specify the file extension for upload, separate by space, i.e: gif jpg png. Leave blank if you allow all file extensions."),
  ); 
  $form['whizzywig_file_upload']['whizzywig_file_size'] = array(
  '#type' => 'textfield',
  '#title' => t('Maximum file size (KB)'),
  '#default_value' => variable_get('whizzywig_file_size', '0'),
  '#description' => t("Specify the maximum file size for upload in KB. Set 0 for unlimited size."),
  ); 
	$form['whizzywig_file_upload']['whizzywig_image_dimension'] = array(
  '#type' => 'textfield',
  '#title' => t('Maximum image dimension'),
  '#default_value' => variable_get('whizzywig_image_dimension', ''),
  '#description' => t("Specify the maximum image dimension, i.e: 200x300. If the image size bigger then this module will automatically resize to this value with proportional size (retain image aspect ratio). Leave blank if you don't need this field."),
  );   
  
  $form['whizzywig_file_resize'] = array(
  '#type' => 'fieldset',
  '#title' => t('File Resize'),
  '#collapsible' => TRUE,
  '#collapsed' => FALSE,
  );
	$form['whizzywig_file_resize']['whizzywig_file_resize_width'] = array(
  '#type' => 'textfield',
  '#title' => t('Default resize width'),
  '#default_value' => variable_get('whizzywig_file_resize_width', '100'),
  '#description' => t("Specify the default width for image resizing."),
  ); 
  $form['whizzywig_file_resize']['whizzywig_file_resize_height'] = array(
  '#type' => 'textfield',
  '#title' => t('Default resize height'),
  '#default_value' => variable_get('whizzywig_file_resize_height', ''),
  '#description' => t("Specify the default height for image resizing.<br /><b>NOTE</b>: If you set value for <b>width</b> and leave <b>height</b> as blank then image will be resizing proportional to width size, and vice versa."),
  ); 
	return system_settings_form($form);
}