<div id="node-<?php print $node->nid; ?>" class="post node<?php print " node-" . $node->type; ?><?php print ($sticky) ? " node-sticky" : ""; ?>">
  <?php if (!$page && $title): ?>
  <h2 class="title"><a href="<?php print $node_url; ?>" title="<?php print $title; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>

  <div class="entry">
    
    <h3>Event on <?php print $field_radio_event_day[0]['view'] ?></h3>
      <p>at <strong><?php print date('h:i A', strtotime($field_date_start[0]['value'])) ?></strong></p>
      
    <?php print $node->content['body']['#value'] ?>
    

  </div>
    
  <?php if ($links): ?>
  <div class="meta">
    <?php print $links; ?>
  </div>
  <?php endif; ?>
</div>