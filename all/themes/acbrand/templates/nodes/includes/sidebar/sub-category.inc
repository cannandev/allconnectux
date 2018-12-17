<?php 
// @todo: move to template.php hook @see allconnect-new template.php
$menu_block = module_invoke('menu_block', 'block_view', '1');
?>

<aside class="aside <?php print $classes; ?> menu-block-1" >
  <?php print render($title_prefix); ?>
  <h3><?php print t('Types of ') . $category_choice; ?></h3>
  <?php print render($title_suffix); ?>
  <?php print render($menu_block['content']); ?>
  <button class="btn-view-offers btn btn-primary" type="button" data-toggle="modal" data-target="#address-capture" filterData="category=<?php print $category_choice; ?>|LIMIT=NA"><?php print t('Find ') . $category_choice . t(' Plans'); ?></button>
</aside>