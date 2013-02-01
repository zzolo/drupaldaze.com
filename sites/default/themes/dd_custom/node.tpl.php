<div id="node-<?php print $node->nid; ?>" class="post node<?php print " node-" . $node->type; ?><?php print ($sticky) ? " node-sticky" : ""; ?>">
  <?php if (!$page && $title): ?>
  <h2 class="title"><a href="<?php print $node_url; ?>" title="<?php print $title; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  

  <div class="entry">
    <?php print $content; ?>
  </div>
    
  <?php if ($links): ?>
  <div class="meta">
    <?php print $links; ?>
  </div>
  <?php endif; ?>
</div>
