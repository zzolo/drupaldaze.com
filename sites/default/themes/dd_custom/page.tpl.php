<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language; ?>" xml:lang="<?php print $language->language; ?>">
<head>
<title><?php print $head_title; ?></title>

<?php print $head; ?><?php print $styles; ?><?php print $scripts; ?>
<script type="text/javascript"><?php /* Needed to avoid Flash of Unstyle Content in IE */ ?> </script>


</head>
<body class="<?php print $layout; ?>">

<div id="wrapper">

<!-- start header -->
<div id="header">
	<div id="menu">
	
	<?php print theme('links', $primary_links); ?>
	
	<!--
		<ul>
			<li class="current_page_item"><a href="#">Homepage</a></li>
			<li><a href="#">Blogs</a></li>
			<li><a href="#">Photos</a></li>
			<li><a href="#">About</a></li>
			<li class="last"><a href="#">Contact</a></li>
		</ul>
	-->
	
	</div>
</div>
<div id="logo">
	<h1><a href="<?php print base_path(); ?>" title="<?php print $site_name; ?>"><?php print $site_name; ?></a></h1>
	<h2><?php print variable_get('site_slogan', ''); ?></h2>
</div>
<!-- end header -->
</div>

<!-- start page -->
<div id="page">
	<!-- start content -->
	<div id="content"<?php if (drupal_is_front_page()): ?> style="width:810px;"<?php endif; ?>>
	
	<?php if ($breadcrumb): ?>
    <div class="breadcrumb"><?php print $breadcrumb; ?></div>
  <?php endif; ?>
  
  <?php if ($messages): ?>
    <?php print $messages; ?>
  <?php endif; ?>
  
  <?php if (drupal_is_front_page() && $mission): ?>
    <div class="mission"><?php print $mission; ?></div>
  <?php endif; ?>
  
  <?php if ($contenttop): ?>
    <div id="content_top"><?php print $contenttop; ?></div>
  <?php endif; ?>
  
  <?php if ($title): ?>
    <h1 class="title"><?php print $title; ?></h1>
  <?php endif; ?>
  
  <?php if ($help): ?>
    <div class="help"><?php print $help; ?></div>
  <?php endif; ?>
  
  <?php if ($tabs): ?>
    <?php print $tabs; ?>
  <?php endif; ?>
	
  <?php print $content; ?> 
  
  <?php print $feed_icons; ?>
  
  <?php if ($contentbottom): ?>
    <div id="content_bottom"><?php print $contentbottom; ?></div>
  <?php endif; ?>
        
	</div>
	<!-- end content -->
	
	
	<!-- start sidebar -->
  <?php if ($right && !(drupal_is_front_page())): ?>
  <div id="sidebar">
    <?php print $right; ?>
  </div>
  <?php endif; ?>
	<!-- end sidebar -->
	
	<div style="clear: both;">&nbsp;</div>
</div>
<!-- end page -->
<!-- start footer -->
<div id="footer">
	<div id="footer-wrap">
	<p id="legal"><?php print $contentfooter; ?> <?php print $footer_message; ?></p>
	</div>
</div>


<?php print $closure; ?>
</body>
</html>