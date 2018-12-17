<?php

/**
 * @file
 * Content page node template.
 *
 * @see node.tpl.php
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <section>
    <div class="container">
      <div class="row">
          <?php print render($content); ?>
      </div>
    </div>
  </section>
</div>
