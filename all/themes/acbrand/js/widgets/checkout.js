(function($){

	$(document).ready(function(){
		AC.Checkout.init();
	});
	
	AC.Checkout = {
		init: function(){
			if($('select')) {
				$('select').selectmenu({
					appendTo:$('#cbSelectOptions')
				});
			}
			if($('#checkoutForm1')){
				AC.FormValidator.init('checkoutForm1');
			}
		}
	}

})(jQuery);