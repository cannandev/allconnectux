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
        <img alt="{{productObject.name}}" ng-src="/common/logos/{{imageDisplayExternalId}}.png" class="img-responsive full-width" />
      </div>
    <?php endif; ?>
    <h3 id="productName_desktop_{{$index}}" ng-bind-html="productObject.name"></h3>
  </div>

  <div id="metaCol" class="result__price col col-xs-12 col-sm-3 col-sm-push-6">
    <div class="price-lockup result__price" ng-if="displayPriceInFixedPoint(productObject.baseRecurringPrice,productObject.providerSource,productObject.promotionPrice,productObject.providerExternalId)">
   
      <span ng-switch="productObject.energyTierList != null">
		<span ng-switch-when="true">
			{{(productObject.energyTierList[2000] * 100).toFixed(1)}}&cent;
		</span>
		<span ng-switch-default>
			{{(displayFixedBaseReccuringPrice * 100).toFixed(1)}}&cent;
		</span>
	</span>
      
      <sup>/kWh&#42;</sup>
    </div>
    <div ng-if="productObject.providerPhoneOnly == true">
      <a type="button" class="btn btn-primary result__btn-call dataProductChoice hidden-sm hidden-md hidden-lg" id="phoneNumberForOrder_{{$index}}" ng-href="tel:{{productObject.callInOnlyNumber}}"><i class="fa fa-phone"></i><span>Call to Order</span></a>
      <div id="callInNumber" class="hidden-xs">
        <span>Call to Order</span>
        <strong>{{productObject.callInOnlyNumber}}</strong>
      </div>
    </div>
    <a id="choosePlan_{{$index}}" type="button" class="btn btn-primary result__btn-select dataProductChoice" href="#" ng-if="productObject.providerPhoneOnly == false" ng-click="showAddressModel('choosethisplan',productObject,'mainPage')">Choose this Plan</a>
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
    <p ng-bind-html="productObject.shortDesc"></p>
  </div>
  
  <div id="promoCol" class="result__promo col col-xs-12 col-sm-3 col-sm-pull-3 hidden-xs" ng-if="productObject.shortDesc==null || productObject.shortDesc==''">
    <!-- <p ng-if="checkForPromotionData(productObject.promotionDescription,productObject.providerExternalId)">{{shortPromo}}</p> -->
    <p ng-bind-html="productObject.shortDesc"></p>
  </div>

  <div class="result__more col-xs-12 col-sm-3">
    <input class="result__more-input" type="checkbox" id="moreDetails_{{$index}}"> 
    <label for="moreDetails_{{$index}}" class="result__more-label more-details dataProductChoice" aria-expanded="false" aria-controls="revealPanel_{{$index}}" data-target="#revealPanel_{{$index}}">Details<i class="glyphicon glyphicon-chevron-down"></i></label>
 </div>
 
  <div id="revealPanel_{{$index}}" class="reveal-panel" aria-hidden="true">
    <p class="reveal-panel_title">Plan Details</p>
    <h3 ng-bind-html="productObject.name"></h3>
    <ul>
      <li ng-repeat="highlight in productObject.marketingHighlights">{{highlight}}</li>
    </ul>
    <ul class="reveal-panel__links">
      <li><a ng-href="{{productObject.EFL_LINK}}" target="_new">Electricity Facts Label</a></li>
      <li><a ng-href="{{productObject.RIGHTS_LINK}}" target="_new">Your Rights as a Customer</a></li>
      <li><a ng-href="{{productObject.TOS_LINK}}" target="_new">Terms of Service</a></li>
    </ul>
    <div class="reveal-panel_promo-box" ng-if="checkForPromotionData(productObject.promotionDescription,productObject.providerExternalId)">
      <p ng-bind-html="productObject.promotionDescription"></p>
    </div>
  </div>
</div> <!-- /.result -->
<?php if (!empty($content['field_disclaimer'])): ?>
<footer class="filters-disclaimer"><?php print render($content['field_disclaimer']); ?></footer>
<?php endif; ?>