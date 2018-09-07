<?php
/**
* @file
* Open page node template.
*
* Available variables:
* - $block: Single block in Mid Banner region.
*
* @see node.tpl.php
*/

// hide node content fields before displaying them
hide($content['field_open_css']);
hide($content['field_open_js']);
hide($content['field_gtm_order_src']);
hide($content['field_gtm_id']);
?>

<?php print render($content); ?>
