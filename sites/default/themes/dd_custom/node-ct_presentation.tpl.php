<div id="node-<?php print $node->nid; ?>" class="post node<?php print " node-" . $node->type; ?><?php print ($sticky) ? " node-sticky" : ""; ?>">
  <?php if (!$page && $title): ?>
  <h2 class="title"><a href="<?php print $node_url; ?>" title="<?php print $title; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>

  <div class="entry">
   
    <div class="presentation-status presentation-status-<?php print ($field_dropdown_status[0]['value']) ? strtolower($field_dropdown_status[0]['value']) : 'confirmed' ?>"><?php print $field_dropdown_status[0]['view'] ?></div>
    
    <div class="presentation-track"><?php print $field_dropdown_track[0]['view'] ?></div>
    
    
    <h3>Presentation on <?php print $field_radio_event_day[0]['view'] ?></h3>
      <p>at <strong><?php print date('h:i A', strtotime($field_date_start[0]['value'])) ?></strong></p>
    
    <?php if ($field_reference_presenters[0]['view']): ?>
    <h3>Presenters</h3>
      <ul>
      <?php
        foreach($field_reference_presenters as $ref) {
          print '<li>'.$ref['view'].'</li>';
        }
      ?>
      </ul>
    <?php endif; ?>
    
    <h3>Description</h3>
    <?php print $node->content['body']['#value'] ?>
    
    <?php if ($field_link_other[0]['view']): ?>
      <h3>Resources</h3>
      <ul>
      <?php
        foreach($field_link_other as $resources) {
          if ($resources['view']) {
            print '<li>'.$resources['view'].'</li>';
          }
        }
      ?>
      </ul>
    <?php endif; ?>

  </div>
    
  <?php if ($links): ?>
  <div class="meta">
    <?php print $links; ?>
  </div>
  <?php endif; ?>
</div>
