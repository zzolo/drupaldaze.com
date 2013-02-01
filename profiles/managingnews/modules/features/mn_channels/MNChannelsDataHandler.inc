<?php

/**
 * @file
 * Include file for MNChannelsDataHandler class.
 */

/**
 * Override delete method of FeedsDataHandler and spare items that have been
 * related to a channel.
 */
class MNChannelsDataHandler extends FeedsDataHandler {

  /**
   * Override parent::delete(). Do not delete items that join to
   * data_table_node. See delete queries.
   */
  public function delete($clause) {

    // Assemble where clause for delete query.
    $where = $values = array();
    $schema = drupal_get_schema($this->table);
    $fields = $schema['fields'];
    foreach ($clause as $key => $value) {
      if (is_array($value)) {
        $where[] = 'base.'. db_escape_string($key) ." {$value[0]} ". db_type_placeholder($fields[$key]['type']);
        $values[] = $value[1];
      }
      else {
        $where[] = 'base.'. db_escape_string($key) ." = ". db_type_placeholder($fields[$key]['type']);
        $values[] = $value;
      }
    }

    // Only execute delete statement if where clause has been populated.
    if (!empty($where)) {

      // First delete records from joined tables, then delete this table's
      // record.
      foreach ($this->joined_tables as $table) {
        if (!empty($where)) {
          db_query('DELETE joined FROM {'. db_escape_table($this->table) .'} base JOIN  {'. db_escape_table($table) .'} joined ON base.'. $this->key .' = joined.'. $this->key .' LEFT JOIN {data_table_node} dn ON base.id = dn.id WHERE dn.id IS NULL AND '. implode(' AND ', $where), $values);
        }
      }
      db_query('DELETE base FROM {'. db_escape_table($this->table) .'} base LEFT JOIN {data_table_node} dn ON base.id = dn.id WHERE dn.id IS NULL AND '. implode(' AND ', $where), $values);
    }

    return db_affected_rows();
  }
}