<div id="filterContainer">
  <aside id="filterPlansDivId" class="filters">
    <nav id="myNavbar" role="navigation">
      <div id="navbarCollapseId">
        <div id="filterToggleOff" class="btn btn-primary fa fa-check" role="button"><span>Done</span></div>
        <h3 class="GuidedNavigationTitle hidden-md hidden-lg" id="filterPlansId">
          <span class="filterPlansTitle">Filters</span>
          <a class="clearFilterLnk dataClearFilter" data-ng-click="resettingArray()">Clear all</a>
        </h3>
        <div class="filters-wrap">         
          <header class="filter-title hidden-xs hidden-sm">
            <h4>Filters</h4>
            <a class="clearFilterLnk dataClearFiltert" data-ng-click="resettingArray()">Clear all</a>
          </header>
          <div class="filter-row" ng-show="contractTerm.length > 0 && contractCount > 0" id="contractLengthFilter">
            <h5 id="contractFilter">Contract Length</h5>
            <div class="DimensionValue"
              data-ng-repeat="contractTermObj in contractTerm" data-ng-if="contractTermObj.countvalue >0">
              <input id="contractlength_filter{{$index}}" class="filter-checkbox dataFilterDim" type="checkbox" 
                onClick="AC.SearchResults.toggleClearLink()"
                data-ng-true-value="'{{contractTermObj.term}}'"
                data-ng-click="termSelection(contractTermObj.term);productDetailsFilter('Contract Length');"
                data-ng-checked="selectedTerm.indexOf(contractTermObj.term) > -1" /> 
              <label for="contractlength_filter{{$index}}">{{contractTermObj.display}} ({{contractTermObj.countvalue}})</label>
            </div>
          </div>

          <div class="filter-row" ng-show="isValidJSONObject('noOfPrices')" id="priceTypeFilter">
            <h5 id="priceFilter">Price</h5>
            <div class="DimensionValue"
              data-ng-repeat="key in sortingOrderForFiltersData(noOfPrices)"
              data-ng-init="value = noOfPrices[key]" data-ng-if="priceCount[key] > 0">
                <input id="pricetype_{{priceCount[key]}}" class="filter-checkbox dataFilterDim" type="checkbox" 
                  onClick="AC.SearchResults.toggleClearLink()"
                  data-ng-true-value="'{{key}}'"
                  data-ng-click="priceSelection(key);productDetailsFilter('Price');"
                  data-ng-checked="selectedPrice.indexOf(key) > -1" /> 
                <label for="pricetype_{{priceCount[key]}}" ng-if="displayCurrency(value)"><span>{{priceValue}} ({{priceCount[key]}})</span></label>
            </div>
          </div>
          
          <div class="filter-row" ng-show="energyPlanTypesTerm.length > 0 && energyPlanTypesCount > 0" id="energyPlanFilter">
            <h5 id="energyPlanTypeFilter">Energy Plan Types</h5>
            <div class="DimensionValue"
              data-ng-repeat="energyPlanTypesTermObj in energyPlanTypesTerm" data-ng-if="energyPlanTypesTermObj.countvalue > 0">
              <input id="energyplan_{{index}}" class="filter-checkbox dataFilterDim" type="checkbox" 
                onClick="AC.SearchResults.toggleClearLink()"
                data-ng-true-value="'{{energyPlanTypesTermObj.term}}'"
                data-ng-click="energyPlanTypeSelection(energyPlanTypesTermObj.term);productDetailsFilter('Energy Plan Types');"
                data-ng-checked="selectedEnergyPlanType.indexOf(energyPlanTypesTermObj.term) > -1" /> 
              <label for="energyplan_{{index}}"><span>{{energyPlanTypesTermObj.display | titleCase}} ({{energyPlanTypesTermObj.countvalue}})</span></label>
            </div>
          </div>            

		      <div  class="filter-row" ng-show="energySourceTypesTerm.length > 0 && energySourceTypesCount > 0" id="energySourceFilter">
            <h5 id="energySourceTypeFilter">Energy Sources</h5>
            <div class="DimensionValue"
              data-ng-repeat="energySourceTypesTermObj in energySourceTypesTerm" data-ng-if="energySourceTypesTermObj.countvalue > 0">
              <input id="energysource_{{index}}" class="filter-checkbox dataFilterDim" type="checkbox" 
                onClick="AC.SearchResults.toggleClearLink()"
                data-ng-true-value="'{{energySourceTypesTermObj.term}}'"
                data-ng-click="energySourceTypeSelection(energySourceTypesTermObj.term);productDetailsFilter('Energy Source Types')"
                data-ng-checked="selectedEnergySourceType.indexOf(energySourceTypesTermObj.term) > -1" /> 
              <label for="energysource_{{index}}"><span>{{energySourceTypesTermObj.display | titleCase}} ({{energySourceTypesTermObj.countvalue}})</span></label>
            </div>
          </div>
        </div><!-- /filters-wrap -->
      </div><!-- /navbarCollapseId -->
    </nav>
    <div class="transparent-bg"></div>
  </aside>  
</div>
