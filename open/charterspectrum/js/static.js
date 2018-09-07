(function () {
  // Variables defined in here will not affect the global scope.
}());

jQuery(document).ready(function($) {
	//toggle disclaimer 
	/*$('.disclaimer .toggle').click(function(){
		$('.glyphicon-triangle-bottom').toggleClass('glyphicon-triangle-top');
	});*/

	//scroll to disclaimer area from an asterisk
	  // var button = e.relatedTarget;
	  // button.preventDefault();
	/*$('#disclaimer-wrapper').on('shown.bs.collapse', function() {
	  var content = $(this);
	  var position = content.offset();
	  $('html, body').animate({scrollTop: position.top}, 'slow');
	});*/

	//copyright dates
	var d = new Date();
	$('.copy-date').html('&copy; ' + d.getFullYear());
});

