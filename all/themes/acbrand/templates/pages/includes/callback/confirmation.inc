<div id="cbStep2" class="cbCheckout" data-ng-controller="CallProviderOrderConfirmation">
  <div class="container">
   <form id="callProviderForm" name="callProviderForm" action="{{flowExecutionUrl}}" method="post">
    <div class="row">
      <div class="col-xs-12">
        <ul id="cbBreadcrumbs">
          <li><span>Checkout</span></li>
          <li class="cb-caret">
            <div></div>
          </li>
          <li class="active"><span>Confirmation</span></li>
        </ul>
      </div>
    </div>
    <div class="cb-cols row">
      <div id="cbConfirm" class="cb-col col-md-8">
        <section id="cbOrderNumber">
          <h2>Your Order Number is {{orderID}}</h2>
          <div>
          <p><strong><span class="textSpecialist">A specialist will call you at {{phone}}</span></strong><span class="textSpecialist"> shortly to configure and confirm your service details and schedule installation.</span></p>
          <p>Note: If you do not receive a call from our specialist within the next 24 hours, please give us a call at {{confirmation_phone}}.</p>
          </div>
        </section>
        <section id="cbNextSteps">
          <h2>Next Steps</h2>
          <ul>
            <li>
              <div>
                <strong>Service Setup:</strong> <span class="textOrder">A specialist will call you to set up your service and configure order and schedule installation.</span>
              </div>
            </li>
            <li>
              <div>
                <strong>Order Confirmation:</strong><span class="textOrder">You will receive an order confirmation by email after your order is configured and scheduled.</span>
              </div>
            </li>
          </ul>
        </section>
      </div>
      <div class="cb-col col-md-4">
        <aside id="cbCart">
          <h2><span>Order Details</span><span>{{orderPlacedOnDate}}</span></h2>
          <div class="cb-cust-info">
            <h3>Customer Information</h3>
            <div>
              <span>{{firstName}} {{lastName}}</span>
              <span>{{email}}</span>
              <span>{{phone}}</span>
            </div>
            <div class="addr3">
              <h4>Service Address:</h4>
              <p>{{addr1}}, {{addr2}}</p>
              <p>{{addr3}}</p>
            </div>
          </div>
             <span ng-if="getImageExternalId(productData)"><img id="provider_logo" src="/common/logos/{{imageExternalId}}.png"/></span>        
          <div class="cb-prod-info">
            <span>{{productData.name}}</span>
            <span><strong>{{productData.monthlyPrice | currency}}<sup>/mo*</sup></strong></span>
          </div>
          <div class="reveal-wrap" aria-role="button">
            <div class="reveal-panel" aria-expanded="false">
              <ul>
              <li ng-if="productData.metadataList.NUM_CHANNELS" class="fa fa-television"><span>TV - {{productData.metadataList.NUM_CHANNELS}} Channels</span></li>
                <li ng-if="productData.metadataList.CONN_SPEED" class="fa fa-wifi" ><span>Internet - Up to {{productData.metadataList.CONN_SPEED}} Mbps</span></li>
              <li ng-if="productData.categories.indexOf('Phone') != -1 || productData.categories.indexOf('PHONE') != -1" class="fa fa-phone"><span>Home Phone</span></li>
              </ul>
              <p>* Installation fees and other fees may apply for equipment or additional features. A credit check and payment information may be required to complete your order.</p>
            </div>
          </div>
        </aside>
        <div id="cbSecureInfo">
          <h4 class="fa fa-lock"><span class="textSafe">Safe and Secure Shopping</span></h4>
          <div>
            <img src="/sites/all/themes/acbrand/img/thawte-icon.jpg" alt="Thawte"/>
            <img src="/sites/all/themes/acbrand/img/trustwave-icon.png" alt="Secure Trustwave"/>
          </div>
        </div>
      </div>
    </div>
    <!--  <input type="hidden" value="callProviderPlaceOrder" name="_eventId" id="_eventId" />  -->
    </form>
  </div> 
</div>