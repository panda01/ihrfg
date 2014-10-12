<?php

/**
 * Implementation of hook_content_default_fields().
 */
function knowledge_database_content_default_fields() {
  $fields = array();

  // Exported field: field_topics
  $fields['knowledge_database-field_topics'] = array(
    'field_name' => 'field_topics',
    'type_name' => 'knowledge_database',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '1',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'knowlege_database_topic' => 'knowlege_database_topic',
      'knowledge_database' => 0,
      'page' => 0,
      'story' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Topics',
      'weight' => '-4',
      'description' => '',
      'type' => 'multiselect_select',
      'module' => 'multiselect',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Topics');

  return $fields;
}
