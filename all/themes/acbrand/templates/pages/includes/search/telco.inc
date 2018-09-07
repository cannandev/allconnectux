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
           <div id="pricingTiersList" class="pricingTiers" ng-bind-html="productObject.promoSummary" ng-if="productObject.promoSummary != undefined"></div>
          <div ng-if="productObject.providerPhoneOnly == true">
            <a href="#" id="choosePlan_{{$index}}" type="button" class="btn btn-primary dataProductChoice hidden-xs" data-toggle="modal" data-target="#product-overlay_{{$index}}" onclick="updateFuseNumber()">Order Now</a>          
            <a ng-if="productObject.isMarchex == false" type="button" class="btn btn-primary fa fa-phone dataProductChoice hidden-sm hidden-md hidden-lg vsnotnumber" id="phoneNumberForOrder_{{$index}}" ng-href="tel:{{productObject.callInOnlyNumber}}"><span>Call to Order</span></a>
            <a ng-if="productObject.isMarchex == true || productObject.isMarchex == undefined" type="button" class="btn btn-primary fa fa-phone dataProductChoice hidden-sm hidden-md hidden-lg" id="phoneNumberForOrder_{{$index}}" ng-href="tel:{{productObject.callInOnlyNumber}}"><span>Call to Order</span></a>
          </div>
          <div ng-if="productObject.providerPhoneOnly == false">
            <a href="#" id="choosePlan_{{$index}}" type="button" class="btn btn-primary dataProductChoice hidden-xs" ng-click="addProductOnOrderAndMoveToCheckout(productObject,'mainPage')">Order Now</a>
            <a ng-if="productObject.isMarchex == false" type="button" class="btn btn-primary fa fa-phone dataProductChoice hidden-sm hidden-md hidden-lg vsnotnumber" id="phoneNumberForOrder_{{$index}}" ng-href="tel:{{productObject.callInOnlyNumber}}"><span>Call to Order</span></a>
            <a ng-if="productObject.isMarchex == true || productObject.isMarchex == undefined" type="button" class="btn btn-primary fa fa-phone dataProductChoice hidden-sm hidden-md hidden-lg" id="phoneNumberForOrder_{{$index}}" ng-href="tel:{{productObject.callInOnlyNumber}}"><span>Call to Order</span></a>            
          </div>
          <p class="disclaimer-link">
            <a href="#" data-toggle="modal" data-target="#disclaimer-toggle_{{$index}}" ng-show="productObject.conditions != 'N/A'">Pricing &amp; Other Info</a> 
          </p>
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
              <p ng-if="productObject.metadataList.CONTRACT_TERM == undefined || productObject.metadataList.CONTRACT_TERM == 0" >No Contract</p>
              <p ng-if="checkForPromotionData(productObject.promotionDescription,productObject.providerExternalId)" class="termsCol__promo">{{shortPromo}}</p>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
    <div id="revealPanel_{{$index}}" class="reveal-panel" aria-hidden="true">
        <p class="reveal-panel_title">Plan Details</p>

        <h3>{{productObject.name}}</h3>
        <div id="moreDetailspricingTiersList" ng-bind-html="productObject.promoSummary" ng-if="productObject.promoSummary != undefined"></div>
        <ul>
            <li ng-repeat="highlight in productObject.marketingHighlights">{{highlight}}</li>
        </ul>
        <div class="reveal-panel_promo-box" ng-if="checkForPromotionData(productObject.promotionDescription,productObject.providerExternalId)">
            <p>{{productObject.promotionDescription}}</p>
        </div>
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

</div>