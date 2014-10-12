<?php

/**
 * Implementation of hook_node_info().
 */
function knowledge_database_node_info() {
  $items = array(
    'knowledge_database' => array(
      'name' => t('Knowledge Database Entry'),
      'module' => 'features',
      'description' => t('An entry into the Knowledge Database. Each entry can be associated with many Knowledge Database taxonomy terms and tags. Each entry can also contain either a PDF for a media file.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'knowlege_database_topic' => array(
      'name' => t('Knowledge Database Topic'),
      'module' => 'features',
      'description' => t('A topic in the knowledge database. An entry can reference multiple topics.'),
      'has_title' => '1',
      'title_label' => t('Topic'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function knowledge_database_views_api() {
  return array(
    'api' => '2',
  );
}
