<!-- call-overlay -->
<div class="call-overlay modal fade" id="product-overlay_{{$index}}" tabindex="-1" role="dialog" aria-labelledby="call-overlay__title">
  <div class="modal-dialog modal-lg" role="document">
    <div class="modal-content">
      <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
      <div class="modal-header text-center flex">
        <h4 class="modal-title" id="call-overlay__title">Call to order and setup your <b>{{productObject.providerName}}</b> service.</h4>
        
        <a href="#" data-fuse data-fuse-format="1-###-###-####" class="call-overlay__phone acdc_XXXXX" ng-href="tel:{{productObject.callInOnlyNumber}}" ng-if="productObject.callInOnlyNumber != undefined && productObject.providerExternalId != '2314635' && productObject.providerExternalId != '15500621' && productObject.providerExternalId != '15500581' && productObject.providerExternalId != '15499221'"> 
          {{productObject.callInOnlyNumber}}
        </a>
       
        <a href="#"  data-format="1-###-###-####" class="call-overlay__phone acdc_XXXXX" ng-href="tel:{{productObject.callInOnlyNumber}}" ng-if="productObject.callInOnlyNumber != undefined && (productObject.providerExternalId == '15500621' || productObject.providerExternalId == '15500581' || productObject.providerExternalId == '15499221' || productObject.providerExternalId == '2314635')"> 
          {{productObject.callInOnlyNumber}}
        </a>
        
      </div>
      <div class="modal-body">
        <h5 class="call-overlay__label">Your Selected Plan</h5>
					<div class="row">
						<div class="col col-xs-12 col-md-6 flex">
              <ul class="call-overlay__plan">
                <li ng-if="productObject.name != undefined">{{productObject.providerName}} {{productObject.name}}</li>
                <li ng-if="productObject.productType != 'NATURALGAS' && productObject.productType != 'ELECTRICITY' && displayPriceInFixedPoint(productObject.baseRecurringPrice,productObject.providerSource,productObject.promotionPrice,productObject.providerExternalId)">
                  ${{displayFixedBaseReccuringPrice}}/mo
                </li>
                <li ng-if="productObject.productType == 'NATURALGAS' || productObject.productType == 'ELECTRICITY'">
                  ${{productObject.perThermRate}}/therm
                </li>
              </ul>
              <ul class="call-overlay__meta">

                <li ng-if="productObject.metadataList.CONTRACT_TERM == undefined" class="ng-hide"></li>
                
                <li ng-if="productObject.metadataList.CONTRACT_TERM == 0">No Contract</li>

                <li ng-if="productObject.metadataList.CONTRACT_TERM != 0 && productObject.metadataList.CONTRACT_TERM != undefined">{{productObject.metadataList.CONTRACT_NAME}} Contract
                </li>

                <li ng-if="productObject.productType == 'NATURALGAS' || productObject.productType == 'ELECTRICITY' && productObject.metadataList.ENERGY_PLAN_TYPE != undefined">
                  {{productObject.metadataList.ENERGY_PLAN_TYPE}}
                </li>

                <li ng-if="productObject.metadataList.NUM_CHANNELS != undefined" >{{productObject.metadataList.NUM_CHANNELS}} TV Channels</li>
                <li ng-if="productObject.metadataList.CONN_SPEED">Up to {{productObject.metadataList.CONN_SPEED}} Mbps</li>
                <li ng-if="productObject.hasPhone">Home Phone Included</li>
              </ul>              
            </div>
            <div class="col col-xs-12 col-md-6 flex">
              <p class="call-overlay__promo" ng-if="!checkForPromotionData(productObject.promotionDescription,productObject.providerExternalId)">Ask Us About Specials and Deals From <b>{{productObject.providerName}}</b></p>
              <p class="call-overlay__promo" ng-if="checkForPromotionData(productObject.promotionDescription,productObject.providerExternalId)">{{productObject.promotionDescription}}</p>
            </div>            
					</div>
      </div>
      <div class="modal-footer">
      	<em>Connecting services for your home has never been easier!</em>
      </div>
    </div>
  </div>
</div><!-- /.call-overlay -->
