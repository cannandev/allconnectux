<?php
$price = isset($content['field_price_amount']) ? render($content['field_price_amount']) : '';
$unit = isset($content['field_price_unit']) ? trim(render($content['field_price_unit'])) : '';
$indicator = isset($content['field_price_disclaimer']) && $content['field_price_disclaimer']['#items'][0]['value'] != 0 ? '<sup>&#42;</sup>' : '';

if ($unit == 'kWh') {
	$price .= '&cent;';
}
else {
	$price = '&#36;' . $price;
}
?>

<?php print '<b>' . $price . '</b> /' . $unit . $indicator; ?>
