<div class="changeLocContents">
  <div class="container">
    <div class="locationTitle">
      Available <span class="currentCat"></span> Plans
    </div>
    <div class="locationAddress">
        <div class="addrInSessions"><span class="addr3"></span><a class="changeLocation dataChangeLocation update_changeAddressBox" ng-click="showAddressUpdateBox()">Change Location</a></div>
    </div>
  </div>
</div>
<div id="displayProducts" style="display: none;" class="container">
  <div class="<?php print $classes; ?> clearfix row results-container"<?php print $attributes; ?>>
    <div class="col-xs-0 col-md-3">
      <div id="filterContainer">
        <aside id="filterPlansDivId" class="filters">
          <nav id="myNavbar" role="navigation">
            <!-- Collect the nav links, forms, and other content for toggling -->
            <div id="navbarCollapseId">
              <div id="filterToggleOff" class="btn btn-primary fa fa-check" role="button"><span>Done</span></div>
              <h3 class="GuidedNavigationTitle" id="filterPlansId">
                <span class="filterPlansTitle">Filters </span>
                <a class="clearFilterLnk dataClearFilter" data-ng-click="resettingArray()">Clear all</a>
              </h3>
              <div class="filters-wrap">
                <div class="filter-row" ng-show="productType.length > 0" id="bundleFilter">
                  <div class="filter-title" id="bundleTypeFilter">Bundle Type</div>
                  <div class="filter-box">
                    <div class="DimensionValue" data-ng-repeat="productTypeObj in productType | orderBy:'countvalue':true" data-ng-if="productTypeObj.countvalue > 0">
                      <input id="bundle_filter{{$index}}" class="filter-checkbox dataFilterDim" type="checkbox"
                        onClick="AC.SearchResults.toggleClearLink()"
                        data-ng-true-value="'{{productTypeObj.type}}'"
                        data-ng-click="productTypeSelection(productTypeObj.type);productDetailsFilter('Bundle Type');"
                        data-ng-checked="selectedProductType.indexOf(productTypeObj.type) > -1" /> 
                      <label for="bundle_filter{{$index}}" class="fa fa-square-o"><span>{{productTypeObj.type}} ({{productTypeObj.countvalue}})</span></label>
                    </div>
                  </div>
                </div>

                <div class="filter-row" ng-show="contractTerm.length > 0 && contractCount > 0" id="contractLengthFilter">
                  <div class="filter-title" id="contractFilter">Contract Length</div>
                  <div class="filter-box">
                    <div class="DimensionValue"
                      data-ng-repeat="contractTermObj in contractTerm" data-ng-if="contractTermObj.countvalue >0">
                      <input id="contractlength_filter{{$index}}" class="filter-checkbox dataFilterDim" type="checkbox" 
                        onClick="AC.SearchResults.toggleClearLink()"
                        data-ng-true-value="'{{contractTermObj.term}}'"
                        data-ng-click="termSelection(contractTermObj.term);productDetailsFilter('Contract Length');"
                        data-ng-checked="selectedTerm.indexOf(contractTermObj.term) > -1" /> 
                      <label for="contractlength_filter{{$index}}" class="fa fa-square-o"><span>{{contractTermObj.display}} ({{contractTermObj.countvalue}})</span></label>
                      <!--<label for="checkbox1"><span></span>&nbsp;{{contractTermObj.term}} ({{contractTermObj.countvalue}})</label>
                    }
                  --></div>
                  </div>
                </div>
                
                <div class="filter-row" ng-show="latinoTerm.length > 0 " id="latinoFilter">
                  <div class="filter-title" id="latinoChannelsFilter">Latino</div>
                  <div class="filter-box">
                    <div class="DimensionValue"
                      data-ng-repeat="latinoTermObj in latinoTerm" data-ng-if="latinoTermObj.countvalue > 0">
                      <input id="latinoterm_filter{{$index}}" class="filter-checkbox dataFilterDim" type="checkbox" 
                        onClick="AC.SearchResults.toggleClearLink()"
                        data-ng-true-value="'{{latinoTermObj.term}}'"
                        data-ng-click="latinoSelection(latinoTermObj.term);productDetailsFilter('Latino');"
                        data-ng-checked="selectedLatino.indexOf(latinoTermObj.term) > -1" /> 
                      <label for="latinoterm_filter{{$index}}" class="fa fa-square-o"><span>{{latinoTermObj.display}} ({{latinoTermObj.countvalue}})</span></label>
                    </div>
                  </div>
                </div>
                
                <div class="filter-row" id="downloadFilter">
                  <div class="filter-title" id="downloadSpeedFilter">Download Speed</div>
                  <div class="filter-box">
                    <div class="DimensionValue"
                      data-ng-repeat="key in sortingOrderForFiltersData(internetSpeed) | orderBy:'internetSpeedCount[key]':true"
                      data-ng-init="value = internetSpeed[key]" 
                      data-ng-if="internetSpeedCount[key] > 0">
                      <input id="download_filter{{$index}}" class="filter-checkbox dataFilterDim" type="checkbox"
                        onClick="AC.SearchResults.toggleClearLink()"
                        data-ng-true-value="'{{key}}'"
                        data-ng-click="downSpeedSelection(key);productDetailsFilter('Download Speed');"
                        data-ng-checked="selectedDownSpeed.indexOf(key) > -1" /> 
                      <label for="download_filter{{$index}}" class="fa fa-square-o"><span>{{value}} ({{internetSpeedCount[key]}})</span></label>
                      <!--<label for="checkbox1"><span></span>&nbsp;{{value}} ({{internetSpeedCount[key]}})</label>-->
                    </div>
                  </div>
                </div>
                <div class="filter-row" ng-show="isValidJSONObject('noOfPrices')" id="priceTypeFilter">
                  <div class="filter-title" id="priceFilter">Price</div>
                  <div class="filter-box">
                    <div class="DimensionValue"
                      data-ng-repeat="key in sortingOrderForFiltersData(noOfPrices)"
                      data-ng-init="value = noOfPrices[key]" data-ng-if="priceCount[key] > 0">
                      <input id="pricetype_{{priceCount[key]}}" class="filter-checkbox dataFilterDim" type="checkbox" 
                        onClick="AC.SearchResults.toggleClearLink()"
                        data-ng-true-value="'{{key}}'"
                        data-ng-click="priceSelection(key);productDetailsFilter('Price');"
                        data-ng-checked="selectedPrice.indexOf(key) > -1" /> 
                      <label for="pricetype_{{priceCount[key]}}" ng-if="displayCurrency(value)" class="fa fa-square-o"><span>{{priceValue}} ({{priceCount[key]}})</span></label>
                    </div>
                  </div>
                </div>
                <div class="filter-row" id="channelFilter">
                  <div class="filter-title" id="channelsTypeFilter">Channels</div>
                  <div class="filter-box">
                    <div class="DimensionValue"
                      data-ng-repeat="key in sortingOrderForFiltersData(noOfChannels) "
                      data-ng-init="value = noOfChannels[key]" data-ng-if="channelsCount[key] > 0">
                      <input id="channel_{{index}}" class="filter-checkbox dataFilterDim" type="checkbox" 
                        onClick="AC.SearchResults.toggleClearLink()"
                        data-ng-true-value="'{{key}}'"
                        data-ng-click="channelsSelection(key);productDetailsFilter('Channels');"
                        data-ng-checked="selectedChannels.indexOf(key) > -1" /> 
                      <label for="channel_{{index}}" class="fa fa-square-o"><span>{{value}} ({{channelsCount[key]}})</span></label>
                    </div>
                  </div>
                </div>
                <div class="filter-row" ng-show="energyPlanTypesTerm.length > 0 && energyPlanTypesCount > 0" id="energyPlanFilter">
                  <div class="filter-title" id="energyPlanTypeFilter">Energy Plan Types</div>
                  <div class="filter-box">
                    <div class="DimensionValue"
                      data-ng-repeat="energyPlanTypesTermObj in energyPlanTypesTerm" data-ng-if="energyPlanTypesTermObj.countvalue > 0">
                      <input id="energyplan_{{index}}" class="filter-checkbox dataFilterDim" type="checkbox" 
                        onClick="AC.SearchResults.toggleClearLink()"
                        data-ng-true-value="'{{energyPlanTypesTermObj.term}}'"
                        data-ng-click="energyPlanTypeSelection(energyPlanTypesTermObj.term);productDetailsFilter('Energy Plan Types');"
                        data-ng-checked="selectedEnergyPlanType.indexOf(energyPlanTypesTermObj.term) > -1" /> 
                      <label for="energyplan_{{index}}" class="fa fa-square-o"><span>{{energyPlanTypesTermObj.display}} ({{energyPlanTypesTermObj.countvalue}})</span></label>
                    </div>
                  </div>
                </div>
                <div ng-show="energySourceTypesTerm.length > 0 && energySourceTypesCount > 0" id="energySourceFilter">
                  <div class="filter-title" id="energySourceTypeFilter">Energy Source Types</div>
                  <div class="filter-box">
                    <div class="DimensionValue"
                      data-ng-repeat="energySourceTypesTermObj in energySourceTypesTerm" data-ng-if="energySourceTypesTermObj.countvalue > 0">
                      <input id="energysource_{{index}}" class="filter-checkbox dataFilterDim" type="checkbox" 
                        onClick="AC.SearchResults.toggleClearLink()"
                        data-ng-true-value="'{{energySourceTypesTermObj.term}}'"
                        data-ng-click="energySourceTypeSelection(energySourceTypesTermObj.term);productDetailsFilter('Energy Source Types')"
                        data-ng-checked="selectedEnergySourceType.indexOf(energySourceTypesTermObj.term) > -1" /> 
                      <label for="energysource_{{index}}" class="fa fa-square-o"><span>{{energySourceTypesTermObj.display}} ({{energySourceTypesTermObj.countvalue}})</span></label>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </nav>
          <div class="transparent-bg"></div>
        </aside>  
      </div>
    </div>
    <div class="col-xs-12 col-md-9">
      <?php if ($otherProvidersNeeded == 'true'): ?>
        <div id="multipleProvidersAlert">
          <div class="close-alert"></div>
          <strong>Hmmm, looks like <span><?php echo $providerName ?></span> is not available at your address.</strong>
          <p>Good news! Multiple partners in your area are offering great services and plans.</p>
          <div class="bg-border"></div>
          <div class="bg-cover"></div>
        </div>
      <?php endif; ?>
      <div id="sortResultsListForm" class="DropdownContaines">
        <div class="compareBtnDiv">
          <a ng-click="CompareProducts();" name="compare" class="comparebtnDown" class="comparebtn"> 
            Compare <span class="resultsCountAC" ng-model="compareResultsCount">{{compareResultsCount}}</span>
          </a>
        </div>
        <div class="sortDiv">
          <label for="sortKey">Sort By:</label>
          <span class="Dropdowns"> 
            <select
              data-ng-change="sortedOrder(data.sortOption)"
              data-ng-model="data.sortOption" name="sortOption" class="dropDownElement serviceType dataSortBy"
              id="sortKey">
                <option value="">Popular</option>
                <option ng-if="productsCount >1" value="'name', false">Plan (A-Z)</option>
                <option ng-if="productsCount >1" value="'name', true">Plan (Z-A)</option>
                <option ng-if="contractCount >1" value="'contractTerm', false">Term
                  (Low-High)</option>
                <option ng-if="contractCount >1" value="'contractTerm', true">Term
                  (High-Low)</option>
                <option ng-if="internetSpeedCountCount >1" value="'internetSpeed', false">Speed
                  (Low-High)</option>
                <option ng-if="internetSpeedCountCount >1" value="'internetSpeed', true">Speed
                  (High-Low)</option>
                <option ng-if="channelsCountCount >1" value="'channels', false">Channels
                  (Low-High)</option>
                <option ng-if="channelsCountCount >1" value="'channels', true">Channels
                  (High-Low)</option>
                <option selected="selected" ng-if="priceCountCount >1" value="'sortPriceField', false">Price
                  (Low-High)</option>
                <option ng-if="priceCountCount >1" value="'sortPriceField', true">Price (High-Low)</option>
            </select>
          </span>
        </div>
        <div role="button" id="filterToggleOn" class="btn btn-primary fa fa-filter"><span>Filter Plans</span></div>
      </div>
      <div id="resultsContainer">
      <?php
        switch($template) {
          case 'electric':
            include_once 'telco.inc';
          break;
          case 'gas':
            include_once 'telco.inc';
          break;
          case 'internet':
          case 'TV':
          case 'phones':
          case 'bundles':
          default:
            include_once 'telco.inc';
          break;
        }
      ?>
      </div>
      <div class="results-btm">
        <div class="compareBtnDiv">
          <a ng-click="CompareProducts();" name="compare" class="comparebtnDown" class="comparebtn"> 
            Compare <span class="resultsCountAC" ng-model="compareResultsCount">{{compareResultsCount}}</span>
          </a>
        </div>
        <div class="pagination-content" ng-show="productSize > paginationCount">
          <div class="ResultsSummary">{{resultsCount}}</div>
          <ul class="pagination pagination-lg pagination-sm pagination-xs" id="pagination-design" style="cursor: pointer;">
            <li ng-click="paginator.perviousPage();" ng-class="paginator.isFirstPage() && 'hide'">
              <a class="pagination-icon-left" style="border: none;">
                <img ng-src="<?php echo $env . path_to_theme() ?>/img/pagination_left.png">
              </a>
            </li>
            <li ng-click="paginator.setPage(i)" ng-repeat="i in [] | forLoop:paginator.lowerLimit():paginator.pageCount() | limitTo : paginator.limitPerPage" ng-class="paginator.page==i && 'active'">       
              <a class="pagination-pg-no" ng-if="paginator.page+2 >= i && paginator.page <= i">
                <b>{{i+1}}</b>
              </a>
            </li>
            <li ng-click="paginator.nextPage()" ng-class="paginator.isLastPage() && 'hide'">
              <a class="pagination-icon-right" style="border: none;">
                <img ng-src="<?php echo $env . path_to_theme() ?>/img/pagination_right.png">
              </a>
            </li>
          </ul>
          <paginator></paginator>
        </div>
      </div>
    </div>
  </div>
</div>