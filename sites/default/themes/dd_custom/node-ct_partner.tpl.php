<div id="node-<?php print $node->nid; ?>" class="post node<?php print " node-" . $node->type; ?><?php print ($sticky) ? " node-sticky" : ""; ?>">
  <?php if (!$page && $title): ?>
  <h2 class="title"><a href="<?php print $node_url; ?>" title="<?php print $title; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>

  <div class="entry">
    
    <?php if ($field_file_logo_image_large[0]['view']): ?>
      <div class="partner-image">
        <?php print $field_file_logo_image_large[0]['view'] ?>
      </div>
    <?php endif; ?>
    
    <?php if ($field_link_organization[0]['view']): ?>
      <p class="partner-link"><?php print $field_link_organization[0]['view'] ?></p>
    <?php endif; ?>
    
    <?php print $node->content['body']['#value'] ?>
    

  </div>
    
  <?php if ($links): ?>
  <div class="meta">
    <?php print $links; ?>
  </div>
  <?php endif; ?>
</div>