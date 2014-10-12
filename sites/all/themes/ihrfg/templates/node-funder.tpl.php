<?php
// $Id: node.tpl.php,v 1.10 2009/11/02 17:42:27 johnalbin Exp $

/**
 * @file
 * Theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: Node body or teaser depending on $teaser flag.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $display_submitted: whether submission information should be displayed.
 * - $links: Themed links like "Read more", "Add new comment", etc. output
 *   from theme_links().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 *   The following applies only to viewers who are registered users:
 *   - node-by-viewer: Node is authored by the user currently viewing the page.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $build_mode: Build mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $build_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * The following variables are deprecated and will be removed in Drupal 7:
 * - $picture: This variable has been renamed $user_picture in Drupal 7.
 * - $submitted: Themed submission information output from
 *   theme_node_submitted().
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see zen_preprocess()
 * @see zen_preprocess_node()
 * @see zen_process()
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix">
  <?php print $user_picture; ?>

  <?php if (!$page): ?>
    <h2 class="title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>

  <?php if ($unpublished): ?>
    <div class="unpublished"><?php print t('Unpublished'); ?></div>
  <?php endif; ?>

<!--
  <?php if ($display_submitted || $terms): ?>
    <div class="meta">
      <?php if ($display_submitted): ?>
        <span class="submitted">
          <?php
            print t('Submitted by !username on !datetime',
              array('!username' => $name, '!datetime' => $date));
          ?>
        </span>
      <?php endif; ?>

      <?php if ($terms): ?>
        <div class="terms terms-inline"><?php print $terms; ?></div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
-->

  <div class="content">
	
<!-- begin custom content -->
<h3 class="field-label">Organizational Mission:</h3>
<?php print $node->content['body']['#value'] ?>

<?php if (isset($node->field_program_mission[0]['value'])) : ?>
<h3>Human Rights Program Mission</h3>
<?php print $node->field_program_mission[0]['view'] ?>
<?php endif; ?>

	<fieldset class="fieldgroup group-grant-info">
	<legend>Grantmaking Information</legend>
	
		<div class="field-container">
		  <div class="field-label">Activities Supported:</div>
		  <div class="field-content">
		    <?php foreach ((array)$node->field_activities_supported as $item) { ?>
		    <div class="field-item"><?php print $item['view'] ?></div>
		    <?php } ?>
		  </div>
		</div>
	
		<div class="field-container">
		  <div class="field-label">Geographic Focus:</div>
		  <div class="field-content">
		    <?php foreach ((array)$node->field_geographic_focus as $item) { ?>
		    <div class="field-item"><?php print $item['view'] ?></div>
		    <?php } ?>
		  </div>
		</div>
	
		<div class="field-container">
		  <div class="field-label">Areas of human rights funding:</div>
		  <div class="field-content">
		    <?php foreach ((array)$node->field_human_rights_areas as $item) { ?>
		    <div class="field-item"><?php print $item['view'] ?></div>
		    <?php } ?>
		  </div>
		</div>	
		
		<?php if (isset($node->field_how_apply[0]['value'])) : ?> 
        <div class="field-container">
		  <div class="field-label">How to apply:</div>
		  <div class="field-content">
		    <?php foreach ((array)$node->field_how_apply as $item) { ?>
		    <?php print $item['view'] ?>
		    <?php } ?>
		  </div>
		</div>	
        <?php endif; ?>

	</fieldset>
    
    <fieldset class="fieldgroup group-organization-info">
	<legend>Organization Information</legend>

		<?php if (isset($node->field_url[0]['url'])) : ?>
        <div class="field-container">
		  <div class="field-label">Website:</div>
		  <div class="field-content"><?php print $node->field_url[0]['view'] ?></div>
		</div>
        <?php endif; ?>
	
		<?php if (isset($node->field_email[0]['value'])) : ?>
        <div class="field-container">
		  <div class="field-label">Email:</div>
		  <div class="field-content"><?php print $node->field_email[0]['view'] ?></div>
		</div>
        <?php endif; ?>
		
		<?php if (isset($node->field_address[0]['value'])) : ?>
        <div class="field-container">
		  <div class="field-label">Address:</div>
		  <div class="field-content">
			  <?php print $node->field_address[0]['view'] ?><br />
			  <?php print $node->field_city[0]['view'] ?><br />
			  <?php if ($node->field_state[0]['view']): ?>
				  <?php print $node->field_state[0]['view'] ?><br />
			  <?php endif; ?>
			  <?php print $node->field_country[0]['view'] ?><br />
			  <?php print $node->field_postal_code[0]['view'] ?>
		  </div>    
		</div>
        <?php endif; ?>
		
		<?php if (isset($node->field_phone[0]['value'])) : ?>
        <div class="field-container">
		  <div class="field-label">Phone:</div>
		  <div class="field-content"><?php print $node->field_phone[0]['view'] ?></div>
		</div>
        <?php endif; ?>
        
	<?php if (isset($node->field_fax[0]['value'])) : ?>
		<div class="field-container">
		  <div class="field-label">Fax:</div>
		  <div class="field-content"><?php print $node->field_fax[0]['view'] ?></div>
		</div>
	<?php endif; ?>
		
	</fieldset>

	<fieldset class="fieldgroup group-contact-info">
	<legend>Contact Information</legend>
	
		<div class="field-container">
		  <div class="field-label">Contact Name:</div>
		  <div class="field-content"><?php print $node->field_contact_name[0]['view'] ?></div>
		</div>
	
		<?php if (isset($node->field_contact_email[0]['value'])) : ?>
        <div class="field-container">
		  <div class="field-label">Contact E-mail:</div>
		  <div class="field-content"><?php print $node->field_contact_email[0]['view'] ?></div>
		</div>
        <?php endif; ?>

		<?php if (isset($node->field_contact_phone[0]['value'])) : ?>
        <div class="field-container">
		  <div class="field-label">Contact Phone:</div>
		  <div class="field-content"><?php print $node->field_contact_phone[0]['view'] ?></div>
		</div>
        <?php endif; ?>
	
		<?php if (isset($node->field_contact_fax[0]['value'])) : ?>
        <div class="field-container">
		  <div class="field-label">Contact Fax:</div>
		  <div class="field-content"><?php print $node->field_contact_fax[0]['view'] ?></div>
		</div>
        <?php endif; ?>
		
	</fieldset>
	
    <p>Last Updated: <?php print date('M j, Y',$node->changed); ?></p>

<!-- end custom content -->

  </div>

  <?php print $links; ?>
</div> <!-- /.node -->
