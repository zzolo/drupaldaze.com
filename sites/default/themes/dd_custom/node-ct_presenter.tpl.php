<div id="node-<?php print $node->nid; ?>" class="post node<?php print " node-" . $node->type; ?><?php print ($sticky) ? " node-sticky" : ""; ?>">
  <?php if (!$page && $title): ?>
  <h2 class="title"><a href="<?php print $node_url; ?>" title="<?php print $title; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>

  <div class="entry">
    
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
    
    <?php if ($field_reference_presentations[0]['view']): ?>
    <h3>Presentations</h3>
      <ul>
      <?php
        foreach($field_reference_presentations as $ref) {
          print '<li>'.$ref['view'].'</li>';
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