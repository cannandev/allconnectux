<div class="progressBar ng-hide" ng-show="progressStatus">
  <div class="col-lg-12">
    <div class="row">
      <div class="container container-loading">
        <div class="loadingMsg">Loading Available Plans and Providers</div>
          <div class="dots-container">
            <div class="dot"></div>
            <div class="dot"></div>
            <div class="dot"></div>
          </div>
      </div>
    </div>
  </div> 
</div>

<header class="row hidden-xs" id="resultLabels">
  <div class="col col-sm-3 ">Plan</div>
  <div class="col col-sm-3">Detail</div>
  <div class="col col-sm-3">Special Offer</div>
  <div class="col col-sm-3"><span ng-click="priceSortForET()">Price <i class="fa fa-caret-down fa-2" id="filter-sort-toggle" aria-hidden="true"></i></span></div>
</header>
<div class="row result-row result" ng-repeat="productObject in productsData | paginate:rowsPerPage | orderBy:predicate:reverse" data-product="{{productObject.produtExternalId}}">
<!-- result-wrap -->
  <div id="nameCol" class="result__name col col-xs-12 col-sm-3">
    <?php if ($otherProvidersNeeded  == 'true'): ?>
      <div ng-if="validateParentExternalId(productObject.parentExternalId,productObject.providerExternalId)" class="product-image-ID">
        <img alt="{{productObject.name}}" ng-src="/common/logos/{{imageDisplayExternalId}}.png" class="result__provider-logo" />
      </div>
    <?php endif; ?>
    <h3 id="productName_desktop_{{$index}}" ng-bind-html="productObject.name"></h3>
  </div>

  <div id="metaCol" class="result__price col col-xs-12 col-sm-3 col-sm-push-6">
    <div class="price-lockup result__price">   
      <div ng-switch="productObject.perThermRate != null">
    		<span ng-switch-when="true">
    			${{productObject.perThermRate}}<sup>/therm</sup>
    		</span>
    		<span ng-switch-default>
    			N/A
    		</span>
    	</div> 
    </div>
    <div ng-if="productObject.providerPhoneOnly == true">
      <a href="#" id="choosePlan_{{$index}}" type="button" class="btn btn-primary dataProductChoice hidden-xs" data-toggle="modal" data-target="#product-overlay_{{$index}}"  onclick="updateFuseNumber()">Order Now</a>          
      <a ng-if="productObject.isMarchex == false" type="button" class="btn btn-primary fa fa-phone dataProductChoice hidden-sm hidden-md hidden-lg vsnotnumber" id="phoneNumberForOrder_{{$index}}" ng-href="tel:{{productObject.callInOnlyNumber}}"><span>Call to Order</span></a>
      <a ng-if="productObject.isMarchex == true || productObject.isMarchex == undefined" type="button" class="btn btn-primary fa fa-phone dataProductChoice hidden-sm hidden-md hidden-lg" id="phoneNumberForOrder_{{$index}}" ng-href="tel:{{productObject.callInOnlyNumber}}"><span>Call to Order</span></a>
    </div>
    <div ng-if="productObject.providerPhoneOnly == false">
      <a href="#" id="choosePlan_{{$index}}" type="button" class="btn btn-primary dataProductChoice hidden-xs" ng-click="addProductOnOrderAndMoveToCheckout(productObject,'mainPage')">Order Now</a>
      <a ng-if="productObject.isMarchex == false" type="button" class="btn btn-primary fa fa-phone dataProductChoice hidden-sm hidden-md hidden-lg vsnotnumber" id="phoneNumberForOrder_{{$index}}" ng-href="tel:{{productObject.callInOnlyNumber}}"><span>Call to Order</span></a>
      <a ng-if="productObject.isMarchex == true || productObject.isMarchex == undefined" type="button" class="btn btn-primary fa fa-phone dataProductChoice hidden-sm hidden-md hidden-lg" id="phoneNumberForOrder_{{$index}}" ng-href="tel:{{productObject.callInOnlyNumber}}"><span>Call to Order</span></a>            
    </div>

    <!-- Pricing & Other Info link.  -->
    <p class="disclaimer-link">
      <a href="#" data-toggle="modal" data-target="#disclaimer-toggle_{{$index}}" ng-show="productObject.conditions != 'N/A'">Pricing &amp; Other Info</a> 
    </p>
    
  </div>

  <?php include_once 'call-overlay.inc' ?>

  <div class="disclaimer modal fade" id="disclaimer-toggle_{{$index}}" tabindex="-1" role="dialog" aria-labelledby="disclaimer-toggle" ng-show="productObject.conditions != 'N/A'">
    <div class="modal-dialog" role="document">
      <div class="modal-content">
          <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-label="Close">
              <span aria-hidden="true">&times;</span>
            </button>
            <h4 class="modal-title">Pricing &amp; Other Info</h4>
          </div>

          <div class="modal-body">
            <p>{{productObject.conditions}}</p>
          </div>
          
      </div>
    </div>
  </div>

  <div id="termsCol" class="result__meta col col-xs-12 col-sm-3 col-sm-pull-3" ng-if="productObject.metadataList.ENERGY_SOURCE_TYPE !='RENEWABLE'">
    <ul>
      <li ng-if="productObject.metadataList.ENERGY_PLAN_TYPE != undefined">{{productObject.metadataList.ENERGY_PLAN_TYPE}}</li>
      <li ng-if="productObject.metadataList.CONTRACT_TERM != 0 && productObject.metadataList.CONTRACT_TERM != undefined" >{{productObject.metadataList.CONTRACT_NAME}}</li>
      <li ng-if="productObject.metadataList.CONTRACT_TERM != undefined && productObject.metadataList.CONTRACT_TERM == 0" >No Contract</li>
      <li ng-if="productObject.metadataList.CONTRACT_TERM == undefined">Contract Term Unavailable</li>
      <li ng-if="productObject.metadataList.ENERGY_SOURCE_TYPE != undefined && productObject.metadataList.ENERGY_SOURCE_TYPE !='TRADITIONAL'">{{productObject.metadataList.ENERGY_SOURCE_TYPE}}</li>
    </ul>
    <ul>
      <li ng-if="productObject.metadataList.ETF != undefined">Early Termination Fee: &#36;{{productObject.metadataList.ETF}}</li>
    </ul>
  </div>
  
  <div id="termsCol" class="result__meta col col-xs-12 col-sm-3 col-sm-pull-3 highlight" ng-if="productObject.metadataList.ENERGY_SOURCE_TYPE =='RENEWABLE'">
    <ul>
      <li ng-if="productObject.metadataList.ENERGY_PLAN_TYPE != undefined">{{productObject.metadataList.ENERGY_PLAN_TYPE}}</li>
      <li ng-if="productObject.metadataList.CONTRACT_TERM != 0 && productObject.metadataList.CONTRACT_TERM != undefined" >{{productObject.metadataList.CONTRACT_NAME}}</li>
      <li ng-if="productObject.metadataList.CONTRACT_TERM != undefined && productObject.metadataList.CONTRACT_TERM == 0" >No Contract</li>
      <li ng-if="productObject.metadataList.CONTRACT_TERM == undefined">Contract Term Unavailable</li>
      <li ng-if="productObject.metadataList.ENERGY_SOURCE_TYPE != undefined && productObject.metadataList.ENERGY_SOURCE_TYPE !='TRADITIONAL'">{{productObject.metadataList.ENERGY_SOURCE_TYPE}}</li>
    </ul>
    <ul>
      <li ng-if="productObject.metadataList.ETF != undefined">Early Termination Fee: &#36;{{productObject.metadataList.ETF}}</li>
    </ul>
  </div>

  <div id="promoCol" class="result__promo col col-xs-12 col-sm-3 col-sm-pull-3" ng-if="productObject.shortDesc!=null && productObject.shortDesc!=''">
    <!-- <p ng-if="checkForPromotionData(productObject.promotionDescription,productObject.providerExternalId)">{{shortPromo}}</p> -->
    <p class="result__promo-short" ng-bind-html="productObject.shortDesc"></p>
  </div>
  
  <div id="promoCol" class="result__promo col col-xs-12 col-sm-3 col-sm-pull-3 hidden-xs" ng-if="productObject.shortDesc==null || productObject.shortDesc==''">
    <!-- <p ng-if="checkForPromotionData(productObject.promotionDescription,productObject.providerExternalId)">{{shortPromo}}</p> -->
    <p class="result__promo-short" ng-bind-html="productObject.shortDesc"></p>
  </div>

  <div class="result__more col-xs-12 col-sm-3">
    <input class="result__more-input" type="checkbox" id="moreDetails_{{$index}}"> 
    <label for="moreDetails_{{$index}}" class="result__more-label more-details dataProductChoice" aria-expanded="false" aria-controls="revealPanel_{{$index}}" data-target="#revealPanel_{{$index}}">Details<i class="glyphicon glyphicon-chevron-down"></i></label>
 </div>
 
  <div id="revealPanel_{{$index}}" class="reveal-panel" aria-hidden="true">
    <p class="reveal-panel_title">Plan Details</p>
    <h3 ng-bind-html="productObject.name"></h3>
    <ul>
      <li ng-repeat="highlight in productObject.marketingHighlights" ng-bind-html="highlight"></li>
    </ul>
    <div class="reveal-panel_promo-box" ng-if="checkForPromotionData(productObject.promotionDescription,productObject.providerExternalId)">
      <p>{{productObject.promotionDescription}}</p>
    </div>
  </div><!-- /.result -->
  
  <?php include_once 'call-overlay.inc' ?>

  <div class="disclaimer modal fade" id="disclaimer-toggle_{{$index}}" tabindex="-1" role="dialog" aria-labelledby="disclaimer-toggle" ng-show="productObject.conditions != 'N/A'">
    <div class="modal-dialog" role="document">
      <div class="modal-content">
          <div class="modal-header">
            <button type="button" class="close" data-dismiss="modal" aria-label="Close">
              <span aria-hidden="true">&times;</span>
            </button>
            <h4 class="modal-title">Pricing &amp; Other Info</h4>
          </div>

          <div class="modal-body">
            <p>{{productObject.conditions}}</p>
          </div>
          
      </div>
    </div>
  </div>

</div>
