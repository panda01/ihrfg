<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function knowledge_database_taxonomy_default_vocabularies() {
  return array(
    'knowledge_database_tags' => array(
      'name' => 'Knowledge Database Tags',
      'description' => '',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '1',
      'module' => 'features_knowledge_database_tags',
      'weight' => '0',
      'nodes' => array(
        'knowledge_database' => 'knowledge_database',
      ),
    ),
  );
}
