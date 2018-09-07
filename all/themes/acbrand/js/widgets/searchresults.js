AC.SearchResults = {
	toggleClearLink: null
},
(function($){

	$(document).ready(function(){
		// console.log('here SR');
		AC.SearchResults.init();
	});

	AC.SearchResults = {
		init: function(){
			$('.addr3').append(AC.currentAddress);
			AC.SearchResults.toggleClearLink = this.clearLink;
			AC.RevealPanel.init('.results-container','.more-details');
			this.addEventListeners();
		},
		clearLink: function(){
			var $chkBoxes = $('.filter-checkbox'),
				$clearLink = $('.clearFilterLnk');

			if($chkBoxes.is(":checked")) {
				$clearLink.show();
			} else {
				$clearLink.hide();
			}
		},
		addEventListeners:function(){
			$('#filterToggleOn').on('click', function(){
				$('body').addClass('toggle-filters');
			});
			$('#filterToggleOff').on('click', function(){
				$('body').removeClass('toggle-filters');
			});
			$(window).resize(function(){
				if(AC.currentMQ == 'mo' || AC.currentMQ == 'xs') {
					AC.Revealer.closeAllPanels();
				}
			});
			if($('#multipleProvidersAlert')) {
				var $alert = $('#multipleProvidersAlert');
				$alert.find('.close-alert').on('click', function(){
					$(this).parent().fadeOut();
				});
			}
		}
	}

})(jQuery);