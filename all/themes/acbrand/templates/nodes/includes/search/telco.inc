<div class="row result" ng-repeat="productObject in productsData | paginate:rowsPerPage | orderBy:predicate:reverse">
  <div class="result-wrap">
    <div id="superCol1" class="col-xs-12 col-sm-3">
      <?php if ($otherProvidersNeeded  == 'true'): ?>
        <div ng-if="validateParentExternalId(productObject.parentExternalId,productObject.providerExternalId)" class="product-image-ID">
          <img alt="{{productObject.name}}" ng-src="<?php echo $trunk ?>common/logos/{{imageDisplayExternalId}}.png" class="img-responsive full-width" />
        </div>
      <?php endif; ?>
      <h3 id="productName_desktop_{{$index}}">{{productObject.name}}</h3>
      <input type="checkbox" id="moreDetails_{{$index}}" />
      <label for="moreDetails_{{$index}}" class="more-details dataProductChoice glyphicon glyphicon-chevron-down" aria-expanded="false" aria-controls="revealPanel_{{$index}}" data-target="#revealPanel_{{$index}}"><span>Details</span></label>
    </div>
    <div id="superCol2" class="col-xs-12 col-sm-9">
      <div class="row">
        <div id="minorCol1" class="col-xs-12 col-sm-4 col-lg-3">
          <div class="price-lockup" ng-if="displayPriceInFixedPoint(productObject.baseRecurringPrice,productObject.providerSource,productObject.promotionPrice,productObject.providerExternalId)">
            ${{displayFixedBaseReccuringPrice}}
            <span class="super">/mo</span>
          </div>
          <div id="pricingTiersList" ng-bind-html="productObject.promoSummary" ng-if="productObject.promoSummary != undefined"></div>
          <div ng-if="productObject.providerPhoneOnly == true">
            <span ng-if="productObject.isMarchex == false">
            <a type="button" class="btn btn-primary fa fa-phone dataProductChoice hidden-sm hidden-md hidden-lg vsnotnumber" id="phoneNumberForOrder_{{$index}}" ng-href="tel:{{productObject.callInOnlyNumber}}"><span>Call to Order</span></a>
            <div id="callInNumber" class="hidden-xs">
              <span>Call to Order</span>
              <strong class="vsnotnumber">{{productObject.callInOnlyNumber}}</strong>
            </div>
            </span>
            <span ng-if="productObject.isMarchex == true || productObject.isMarchex == undefined">
            <a type="button" class="btn btn-primary fa fa-phone dataProductChoice hidden-sm hidden-md hidden-lg" id="phoneNumberForOrder_{{$index}}" ng-href="tel:{{productObject.callInOnlyNumber}}"><span>Call to Order</span></a>
            <div id="callInNumber" class="hidden-xs">
              <span>Call to Order</span>
              <strong>{{productObject.callInOnlyNumber}}</strong>
            </div>
            </span>
          </div>
          <a id="choosePlan_{{$index}}" type="button" class="btn btn-primary dataProductChoice" href="#" ng-if="productObject.providerPhoneOnly == false" ng-click="addProductOnOrderAndMoveToCheckout(productObject,'mainPage')">Add to Cart</a>
        </div>
        <div id="minorCol2" class="col-xs-12 col-sm-8 col-lg-9">
          <div class="row">
            <div class="col-xs-12 col-sm-3 meta-wrap fa fa-television" ng-class="{ 'inactive' : !productObject.hasTV }">
              <p ng-if="productObject.metadataList.NUM_CHANNELS != undefined">{{productObject.metadataList.NUM_CHANNELS}} Channels</p>
              <p ng-if="!productObject.metadataList.NUM_CHANNELS">TV</p>

              <div ng-if="validateChannelLineUpLinkAvailability(productObject.isChannelLineupProvider,imageCategory)">
                <a id="channelLineup_{{$index}}" href="#" ng-click="viewChannelLineup(productObject.providerExternalId,productObject.providerName,productObject.parentExternalId,productObject.produtExternalId);">Channel Lineup</a>
              </div>  
            </div>
            <div class="col-xs-12 col-sm-3 meta-wrap fa fa-wifi" ng-class="{ 'inactive' : !productObject.hasInternet }">
              <p ng-if="productObject.metadataList.CONN_SPEED">Up to {{productObject.metadataList.CONN_SPEED}} Mbps</p>
              <p ng-if="!productObject.metadataList.CONN_SPEED">Internet</p>
            </div>
            <div class="col-xs-12 col-sm-3 meta-wrap fa fa-phone" ng-class="{ 'inactive' : !productObject.hasPhone }">
                <p>Home Phone</p>
            </div>
            <div id="termsCol" class="col-xs-12 col-sm-3">
              <p ng-if="productObject.metadataList.CONTRACT_TERM != 0 && productObject.metadataList.CONTRACT_TERM != undefined" >{{productObject.metadataList.CONTRACT_NAME}} Contract</p>
              <p ng-if="productObject.metadataList.CONTRACT_TERM != undefined && productObject.metadataList.CONTRACT_TERM == 0" >No Contract</p>
              <p ng-if="productObject.metadataList.CONTRACT_TERM == undefined">Contract Term Unavailable</p>
              <p ng-if="checkForPromotionData(productObject.promotionDescription,productObject.providerExternalId)">{{shortPromo}}</p>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div id="revealPanel_{{$index}}" class="reveal-panel" aria-hidden="true">
    <p class="reveal-panel_title">Plan Details</p>
    
    <h3>{{productObject.name}}</h3>
    <ul>
      <li ng-repeat="highlight in productObject.marketingHighlights">{{highlight}}</li>
    </ul>
    <div class="reveal-panel_promo-box" ng-if="checkForPromotionData(productObject.promotionDescription,productObject.providerExternalId)">
      <p>{{productObject.promotionDescription}}</p>
    </div>
  </div>
</div>