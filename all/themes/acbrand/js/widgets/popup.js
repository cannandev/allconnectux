/* -------------------------------------------
//  Search results popup block
// -------------------------------------------*/

// Use #block-ac-results-phone-popup ID for JS targeting
// Use the global Drupal.settings.popupTimer property for setTimeout()
// 
(function($){
	$(document).ready(function(){
		AC.Popup.init();
	});

	AC.Popup = {
		time: null,
		timer: null,
		deactivateTimer: false,
		$popup: null,

		init: function(){
			this.$popup = $('#block-ac-results-phone-popup');

			if(this.$popup && AC.currentMQ !== 'mo' && AC.currentMQ !== 'xs') { //Check for reference and Media Query size
				this.time = (Drupal.settings.popupTimer*1000); //Convert CMS value to seconds
				this.addEventListeners();

				AC.Popup.activateTimeout(); //Start the timer
			}
		},

		addEventListeners:function(){
			$(window).on('click', function(){ //Listen for activity on the page
				if(!AC.Popup.deactivateTimer) { //Has the popup occurred yet?
					AC.Popup.activateTimeout(); //Something was clicked, reset timer
				}
			});
			this.$popup.find('.block-header').on('click', function(){ //Add Event for minimize/maximize 
				var isMinimized = $(this).parents('#block-ac-results-phone-popup').hasClass('closed');
				AC.Popup.togglePopup(isMinimized);
			});
		},

		activateTimeout: function(){ //Resets the timer
			this.timer = window.setTimeout(function(){
				AC.Popup.showPopup();
			}, this.time);
		},

		showPopup: function() {
			this.$popup.show(function(){
				AC.Popup.$popup.find('.block-content-wrap').animate({
					opacity:1
				},300);
			});
			this.deactivateTimer = true; //Popup occurred, deactivate the timer
		},

		togglePopup: function(isMinimized){
			if(isMinimized) {
				AC.Popup.$popup.removeClass('closed');
			} else {
				AC.Popup.$popup.addClass('closed');
			}
		}
	}
})(jQuery);