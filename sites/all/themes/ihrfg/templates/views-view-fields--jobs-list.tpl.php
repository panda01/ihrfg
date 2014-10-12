<?php
// $Id: views-view-fields.tpl.php,v 1.6 2008/09/24 22:48:21 merlinofchaos Exp $
/**
 * @file views-view-fields.tpl.php
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->separator: an optional separator that may appear before a field.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
 
/**
 * View Fields
 * $fields[picture]->content == User: Picture
 * $fields[comment_count]->content == Node: Comment count
 * $fields[title]->content == Node: Title
 * $fields[name]->content == User: Name
 * $fields[created]->content == Node: Post date
 * $fields[teaser]->content == Node: Teaser
 * $fields[view_node]->content == Node: Link
 * Fields are output like this: <?php print $fields[title]->content; ?>
 */
?>
<p class="jobs_date_posted">Posted on: <?php print $fields[created]->content; ?></p>
<h2><?php print $fields[field_job_title_value]->content; ?></h2>
<p class="jobs_organization"><?php print $fields[field_organization_value]->content; ?></p>
<?php print $fields[teaser]->content; ?>
<!--<div class="read_more"><a href="<?php //print $fields[path]->content; ?>"><img src="/sites/all/themes/zen/ihrfg/images/blue-arrow.png" alt="read more" title="Read More" /></a></div>-->
<p class="application_deadline">Application Deadline: <?php print $fields[field_application_deadline_value]->content; ?></p>