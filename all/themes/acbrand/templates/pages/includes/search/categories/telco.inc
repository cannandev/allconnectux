
<!-- <div class="infoMsg alert-primary" role="alert">
  <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
  {{redirectResultsMessage}}
</div> -->

{{redirectResultsMessage}}<br /><br />

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

<header class="row hidden-xs " id="resultLabels">
  <div class="col col-sm-3 ">Provider</div>
  <div class="col col-sm-3">
    <!-- <?php echo ($template == 'VIDEO') ? 'TV' : $template; ?> -->
    <?php print $template_label; ?>
  </div>
  <div class="col col-sm-3">Details</div>
  <div class="col col-sm-3"><span ng-click="priceSortForET()">Price <i class="fa fa-caret-down fa-2" id="filter-sort-toggle" aria-hidden="true"></i></span></div>
</header>
<div class="row result-row result" ng-repeat="productObject in productsData | paginate:rowsPerPage | orderBy:predicate:reverse" data-product="{{productObject.produtExternalId}}">
  <div id="nameCol" class="result__name col col-xs-12 col-sm-3">
    <?php if ($otherProvidersNeeded  == 'true'): ?>
      <div ng-if="validateParentExternalId(productObject.parentExternalId,productObject.providerExternalId)" class="product-image-ID">
        <img alt="{{productObject.name}}" ng-src="/common/logos/{{imageDisplayExternalId}}.png" class="result__provider-logo" />
      </div>
    <?php endif; ?>
    <h3 id="productName_desktop_{{$index}}">{{productObject.name}}</h3>
  </div>

  <div id="metaCol" class="result__price col col-xs-12 col-sm-3 col-sm-push-6">
    <div class="price-lockup result__price" ng-if="displayPriceInFixedPoint(productObject.baseRecurringPrice,productObject.providerSource,productObject.promotionPrice,productObject.providerExternalId)">
      <span>${{displayFixedBaseReccuringPrice}}</span>
      <sup>/mo</sup>
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

  <div id="termsCol" class="result__meta col col-xs-12 col-sm-3 col-sm-pull-3">
    <p class="text-center" ng-if="productObject.hasInternet && productObject.productType == 'INTERNET'">
      <i class="result__type-icon fa fa-wifi fa-2x"></i>
      <span class="result__meta-list" ng-if="productObject.metadataList.CONN_SPEED">Up to {{productObject.metadataList.CONN_SPEED}} Mbps Download Speed</span>
      <span class="result__meta-list" ng-if="!productObject.metadataList.CONN_SPEED">Internet</span>
    </p>
    <p class="text-center" ng-if="productObject.hasTV && productObject.productType == 'VIDEO'">
      <i class="result__type-icon fa fa-television fa-2x"></i>
      <span class="result__meta-list" ng-if="productObject.metadataList.NUM_CHANNELS">{{productObject.metadataList.NUM_CHANNELS}} Channels</span>
      <span class="result__meta-list" ng-if="!productObject.metadataList.NUM_CHANNELS">TV</span>
      <div class="result__meta-channel" ng-if="validateChannelLineUpLinkAvailability(productObject.isChannelLineupProvider,imageCategory)">
        <a id="channelLineup_{{$index}}" href="#" ng-click="viewChannelLineup(productObject.providerExternalId,productObject.providerName,productObject.parentExternalId,productObject.produtExternalId);">Channel Lineup</a>
      </div> 
    </p>
    <p class="text-center" ng-if="productObject.hasPhone && productObject.productType == 'PHONE'">
      <i class="result__type-icon fa fa-phone fa-2x"></i>
      <span class="result__meta-list">Phone Included</span>
    </p>
  </div>
  
  <div id="promoCol" class="result__promo col col-xs-12 col-sm-3 col-sm-pull-3">
    <p ng-if="productObject.metadataList.CONTRACT_TERM != 0 && productObject.metadataList.CONTRACT_TERM != undefined" >{{productObject.metadataList.CONTRACT_NAME}} Contract</p>
    <p ng-if="productObject.metadataList.CONTRACT_TERM == undefined || productObject.metadataList.CONTRACT_TERM == 0">No Contract</p>
    <p ng-if="checkForPromotionData(productObject.promotionDescription,productObject.providerExternalId)" class="result__promo-short"><i class="fa fa-gift fa-2x"></i><span>{{shortPromo}}</span></p>
  </div>
  
  <!-- <div id="promoCol" class="result__promo col col-xs-12 col-sm-3 col-sm-pull-3 hidden-xs" ng-if="productObject.shortDesc==null || productObject.shortDesc==''">

    <p ng-bind-html="productObject.shortDesc"></p>
  </div> -->

  <div class="result__more col-xs-12 col-sm-3">
    <input class="result__more-input" type="checkbox" id="moreDetails_{{$index}}"> 
    <label for="moreDetails_{{$index}}" class="result__more-label more-details dataProductChoice" aria-expanded="false" aria-controls="revealPanel_{{$index}}" data-target="#revealPanel_{{$index}}">Details<i class="glyphicon glyphicon-chevron-down"></i></label>
 </div>
 
  <div id="revealPanel_{{$index}}" class="reveal-panel" aria-hidden="true">
    <p class="reveal-panel_title">Plan Details</p>
    <h3 ng-bind-html="productObject.name"></h3>
    <div id="moreDetailsPricingTiersList" ng-bind-html="productObject.promoSummary" ng-if="productObject.promoSummary != undefined"></div>
    <ul>
      <li ng-repeat="highlight in productObject.marketingHighlights">{{highlight}}</li>
    </ul>
    <div class="reveal-panel_promo-box" ng-if="checkForPromotionData(productObject.promotionDescription,productObject.providerExternalId)">
      <p>{{productObject.promotionDescription}}</p>
    </div>
  </div><!-- /.result -->

</div>
