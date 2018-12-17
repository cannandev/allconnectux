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
                <img ng-src="<?php print $base_path . drupal_get_path('theme', 'acbrand'); ?>/img/pagination_left.png">
              </a>
            </li>
            <li ng-click="paginator.setPage(i)" ng-repeat="i in [] | forLoop:paginator.lowerLimit():paginator.pageCount() | limitTo : paginator.limitPerPage" ng-class="paginator.page==i && 'active'">       
              <a class="pagination-pg-no" ng-if="paginator.page+2 >= i && paginator.page <= i">
                <b>{{i+1}}</b>
              </a>
            </li>
            <li ng-click="paginator.nextPage()" ng-class="paginator.isLastPage() && 'hide'">
              <a class="pagination-icon-right" style="border: none;">
                <img ng-src="<?php print $base_path . drupal_get_path('theme', 'acbrand'); ?>/img/pagination_right.png">
              </a>
            </li>
          </ul>
          <paginator></paginator>
        </div>