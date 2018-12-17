//Exposed Globals
AC = {
	currentMQ:null,
	currentAddress:null,
	FormValidator:null,
	RevealPanel:null
},

(function($){
	$(document).ready(function(){
		
		$('#street1, #aptCondo, #apartment, #cityStateZip, #zip, #lastname, #zipCode, #bestContactNumber').attr('autocomplete','off');

		// code for hiding the sidebar in Electricity pages
		if ($("body").hasClass("page-node-12")) {
		    $('.sidebar .menu-block-1').hide();
		}

		AC.init();

		$(document).on('click', '#SubmitZip', function(e) {
	        var zipval = $("#zipcode").val();
	        
	        $.getJSON("/sites/all/themes/acbrand/js/zipcodes.json", checkIndex);

	        function checkIndex(results) {
	            if ($.inArray(zipval, results.ziparray) > -1) {
	                window.location.assign('https://www.choosetexaspower.org/compare-offers/?Zip='+zipval+'&Submit=Compare&Type=Home');
	                //window.location.assign('/showcase.html?'+zipval);
	            } else {
	                window.location.assign('https://www.chooseenergy.com/shop/residential/electricity/'+zipval+'/');
	            }
        	}
	        
	    });

	    $("#zipcode").keyup(function(event) {
		    if (event.keyCode === 13) {
		        $("#SubmitZip").click();
		    }
		});
	    var url = window.location.href;
	    if(url.indexOf("/electricity-utilities.html") != -1){
	    	$(".modal_all").remove();
	    }else{
	    	$(".modal_Et").remove();
	    }
	    
	    $(document).on('click', '#modal_submitZip', function(e) {
	        var zipval = $("#modal_zipcode").val();
	        
	        $.getJSON("/sites/all/themes/acbrand/js/zipcodes.json", checkIndex);

	        function checkIndex(results) {
	            if ($.inArray(zipval, results.ziparray) > -1) {
	                window.location.assign('https://www.choosetexaspower.org/compare-offers/?Zip='+zipval+'&Submit=Compare&Type=Home');
	            } else {
	                window.location.assign('https://www.chooseenergy.com/shop/residential/electricity/'+zipval+'/');
	            }
        	}
	        
	    });
	});

	AC = {

		init: function(){
			AC.currentMQ = this.getCurrentMQ();
			if($('#zipBlock')) {
				AC.currentAddress = $('#zipBlock').val();
			}
			AC.FormValidator = this.Form;
			AC.RevealPanel = this.Revealer;
			this.addEventListeners();
		},

		addEventListeners:function(){
			$(window).resize(function(){
				var tempMQ = AC.getCurrentMQ();

				if(AC.currentMQ !== tempMQ) {
					AC.currentMQ = tempMQ;
				}
			});

			$('#main-menu a').click(function(e){
				var isZipCheck = true;
				var cat = $(this).attr('class');
				//@todo check if has class
				// check for address variable from ACDC
				if(typeof (cat)!='undefined' && cat.toLowerCase() == 'electricity' && typeof ($('#zipBlock').val()) != 'undefined' && $('#zipBlock').val() !=null && $('#zipBlock').val().trim() != '' ){
					e.preventDefault();
					redirectZip().promise().done(function() {
					});
				} 
				else if(isZipCheck && cat && _isvalidAdress) {
					AC.getCategoryResults(cat);
					e.preventDefault();
				}
			});

      		// Show disclaimer if the price asterisk is present.
			if($(".filter-price sup").length){
      			$(".filters-disclaimer").removeClass('hidden');
    		}			
		},

		//PANEL REVEALER
		//STRUCTURE REQUIRES ALL PANELS TO HAVE unique ID, .reveal-panel & aria-hidden AND ALL BUTTONS TO HAVE aria-expanded & aria-controls
		Revealer: { 
			$parent: null,
			$obj: null,

			init: function($parent,$obj) { //must be class/ID prefixed with # or . for event delegation to work properly
				this.$obj = $obj;
				this.$parent = $parent;
				this.addEventListeners();
			},

			addEventListeners: function(){
				$(this.$parent).on('click',this.$obj, function(){
					var $this = $(this);

					AC.Revealer.togglePanel($this);
				});
			},

			togglePanel: function($obj){
				var panelID = $obj.attr('data-target'),
					$targetPanel = $(panelID);
				
				if($obj.attr('aria-expanded') == 'true') {
					AC.Revealer.closePanel($obj, $targetPanel);
				} else {
					AC.Revealer.openPanel($obj, $targetPanel);
				}
			},

			openPanel: function($this, $targetPanel){
				$targetPanel.stop().slideDown().attr('aria-hidden', 'false');
				$this.attr('aria-expanded', 'true');
			},

			closePanel: function($this, $targetPanel){
				$targetPanel.stop().slideUp().attr('aria-hidden', 'true');
				$this.attr('aria-expanded', 'false');
			}
		},

		//FORM VALIDATION
		Form: {
			$form: null,
			inputs: null,
			hasErrors: false,
			ERR_REQ:'Required',
			ERR_TXT:'Please only use text in this field',
			ERR_EMAIL:'Please enter a valid email address',
			ERR_PHONE:'Please enter a valid phone number',

			init: function(ID){
				this.$form = $('#'+ID);
				this.inputs = this.$form.find("*[data-rules]");

				this.addEventListeners();
			},

			addEventListeners: function(){
				this.$form.submit(function(e){
					AC.Form.errorReset();
					AC.Form.validate();
					if(AC.Form.hasErrors) {
						e.preventDefault();
					}
				});
				this.inputs.on('focusin click change', function(){
					var $this = $(this),
						$thisParent = $this.parent(),
						$thisErrMsg = $thisParent.find('.err-msg');

					if($thisParent.hasClass('err')) {
						$thisParent.removeClass('err');
						$thisParent.removeClass('err-req');
					}
					$thisErrMsg.empty();
				});
			},

			validate: function(){
				$(this.inputs).each(function(i){
					var $this = $(this),
						inputType = $this.attr('type'),
						rules = $this.attr('data-rules').split('|');

					if(inputType == undefined){
						inputType = $this.prop('tagName');
					}

					$(rules).each(function(r){
						var rule = rules[r];

						switch(rule) {
							case 'req'://Any inputs // Checks for empty
								if(!AC.Form.validateEmpty($this,inputType)) {
									AC.Form.hasErrors = true;
								}
							break;
							case 'txt'://Text fields only // Checks for numbers
								if(!AC.Form.validateTextOnly($this)){
									AC.Form.hasErrors = true;
								}
							break;
							case 'email'://Text fields only // Checks for email format
								if(!AC.Form.validateEmail($this)){
									AC.Form.hasErrors = true;
								}
							break;
							case 'phone'://Text fields only // Checks for phone format
								if(!AC.Form.validatePhone($this)) {
									AC.Form.hasErrors = true;
								}
							break;
						}
					});
				});
			},

			//Validation methods
			validateEmpty: function($this,inputType){
				var hasErrors = false;

				switch(inputType) {
					case 'text':
						if($this.val() === "") {
							hasErrors = true;
						}
					break;
					case 'checkbox':
						if(!$this.is(':checked')){
							hasErrors = true;
						}
					break;
					case 'select':
						if($this.val() === "" || $this.val() === "none") {
							hasErrors = true;
						}
					break;
				}

				if(hasErrors) {	
					$this.parent('.input-wrap').addClass('err-req').addClass('err');

					return false;
				} else {
					return true;
				}
			},
			validateTextOnly: function($this){
				var thisVal = $this.val(),
					numbers = /^[A-Za-z]+$/;  

      			if(numbers.test(thisVal)) {
      				return true;
      			} else {
      				$this.parent('.input-wrap').addClass('err');
      				$this.parent('.input-wrap').find('.err-msg').html(AC.Form.ERR_TXT);

      				return false;
      			}
			},
			validateEmail: function($this){
				var emailFilter=/^.+@.+\..{2,5}$/,
					illegalChars= /[\(\)\<\>\,\;\:\\\/\"\[\]]/;

				if ((!(emailFilter.test($this.val()))) || ($this.val().match(illegalChars))) {
					$this.parent('.input-wrap').addClass('err');
					$this.parent('.input-wrap').find('.err-msg').html(AC.Form.ERR_EMAIL);

					return false;
				} else {
					return true;
				}
			},
			validatePhone: function($this){
				var stripped = $this.val().replace(/[\(\)\.\-\ ]/g, '');
		        //strip out acceptable non-numeric characters
		        if ((isNaN(stripped) && stripped.length != 0) || (stripped.length != 10 && stripped.length!=0)) { //if not a number or left blank, return false
		            $this.parent('.input-wrap').addClass('err');
		            $this.parent('.input-wrap').find('.err-msg').html(AC.Form.ERR_PHONE);

		            return false;
		        } else {
		            return true;
		        }
			},

			//RESET VALIDATIONS
			errorReset: function(){
				AC.Form.hasErrors = false;
				$('.err').removeClass('err');
				$('.err-req').removeClass('err-req');
				$('.err-msg').empty();
			}
		},

		//UTILITY//
		getCurrentMQ: function(){
			var mq = $('body').css('zIndex');

			switch(mq) {
				case '5':
					return 'lg';
				break;
				case '4':
					return 'md';
				break;
				case '3':
					return 'sm';
				break;
				case '2':
					return 'xs';
				break;
				default:
					return 'mo';
				break;
			}
		},

		//ACDC//
		getCategoryResults: function(category){
			// Add values to hidden form elements.
			$("#filterData").val('category=' + category);
			$("#categoryType").val(category);
			$("#_eventId").val("submitAddressEvent");
			$("#productsSummuryForm").submit();
		},
	}
})(jQuery);



function redirectZip(){
	var zipVal =$('#zipBlock').val().substring($('#zipBlock').val().length,$('#zipBlock').val().length -10);
	zipVal=zipVal.split("-")[0];
	 var deferred = jQuery.Deferred();
	$.ajax({
		url: "/sites/all/themes/acbrand/js/zipcodes.json",
		type: 'GET',
		async: false,
		success: function (data) {
			if ($.inArray(zipVal, data.ziparray) > -1) {
				deferred.resolve(window.location = 'https://www.choosetexaspower.org/compare-offers/?Zip='+zipVal+'&Submit=Compare&Type=Home');
			} else {
				deferred.resolve(window.location = 'https://www.chooseenergy.com/shop/residential/electricity/'+zipVal+'/');
			}
		}
	});
	return deferred.promise();
}

function updateFuseNumber(){
	if(typeof fuse === 'function'){
		fuse('placeNumbers');
	}
}