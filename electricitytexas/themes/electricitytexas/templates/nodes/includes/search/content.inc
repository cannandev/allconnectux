<div class="changeLocContents">
  <div class="container">
    <div class="locationTitle">
      <span id="totalProducts">{{productSize}}</span> Plans Available
    </div>
    <div class="locationAddress">
        <div class="addrInSessions"><span class="addr3"></span><a class="changeLocation dataChangeLocation update_changeAddressBox" ng-click="showAddressModel('changeLocation','','');">Change Location</a></div>
    </div>
  </div>
</div>
  
  <!-- filter-btn -->
  <div class="filter-btn-wrapper container">
    <button role="button" id="filterToggleOn" class="btn btn-primary" aria-hidden="true"> 
     <span class="fa fa-filter"></span> Filters
    </button>     
  </div> 

  <!-- alerts -->
  <?php include_once 'alerts.inc'; ?>

<div id="displayProducts" class="container">
  <div class="<?php print $classes; ?> clearfix row results-container"<?php print $attributes; ?>>
    <div class="col-xs-0 col-md-3">
      <!-- filters -->
      <?php include_once 'filter-types.inc'; ?>
    </div>
    <div class="col-xs-12 col-md-9">
      <!-- results -->
      <div id="resultsContainer">
        <?php include_once 'electricity.inc'; ?>
      </div>
      <div class="results-btm">
        <!-- compare and pagination -->
        <?php include_once 'compare.inc'; ?>
      </div>
    </div>
  </div><!-- /.results-container -->
</div><!-- /.displayProducts -->