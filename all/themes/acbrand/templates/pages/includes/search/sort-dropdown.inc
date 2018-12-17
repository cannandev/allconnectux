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