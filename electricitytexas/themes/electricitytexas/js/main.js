//Exposed Globals

(function($){
  $(document).ready(function(){
    ET.init();
    
  });

  ET = {

    init: function(){
      this.addEventListeners();
    },

    addEventListeners:function(){
      // Show disclaimer if the price asterisk is present.
      if($(".filter-price sup").length){
        $(".filters-disclaimer").removeClass('hidden');
      }
      var settings = Drupal.settings.ET;
      // Disable address capture if address is in session or if admin option is checked.
      if(settings && settings.hideAddressCapture == true){
        $('.btn-view-offers').removeAttr('data-target data-toggle');
      }
      ET.checkFilter();  // Move this call to results_page hook in template.php
    },
    checkFilter:function(){
      // Show more details if a product was filtered by ID.      
      console.log('Branded: Checking ID filters...');
      var filters = $("#filterDataET").val();
      if (filters != undefined) {
        var filter = filters.split("|");
        $(filter).each(function(i){
          var links = $(".reveal-panel a[href*='" + filter[i] + "']");
          if (links[0] != undefined) {
            console.log("Branded: Matching ID found. Opening more details...");
            // $(links[0]).parents(".reveal-panel").show();
            var panel = $(links[0]).parents(".reveal-panel");
            ET.revealPanel(panel);
          }
          
          // change aria-expanded attribute on more less link
        });
      }
    },
    revealPanel:function(panel){
      panel.slideDown();
      panel.siblings(".result__more").find("input").prop("checked", true);
      // panel.siblings("#nameCol").find(".more-details").text("Less Details");
      // panel.siblings("#nameCol").find(".more-details").removeClass("glyphicon-chevron-down").addClass("glyphicon-chevron-up");

    },
    closePanel:function(){
    },
    submitProductsForm: function(category){
      // Add values to hidden form elements.
      $("#filterData").val('category=' + category);
      $("#categoryType").val(category);
      $("#_eventId").val("submitAddressEvent");
      $("#productsSummuryForm").submit();
    },
  }
})(jQuery);