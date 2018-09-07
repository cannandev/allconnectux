<div id="cbStep1" class="cbCheckout" data-ng-controller="CallProviderCheckoutContoller">
  <div class="container">
  <form id="checkoutForm1" name="callProviderForm" action="{{flowExecutionUrl}}" method="post">   
    <div class="row">
      <div class="col-xs-12">
        <ul id="cbBreadcrumbs">
          <li class="active"><span>Checkout</span></li>
          <li class="cb-caret">
            <div></div>
          </li>
          <li><span>Confirmation</span></li>
        </ul>
      </div>
    </div>
    <div class="cb-cols row"> 
      <div id="cbForm" class="cb-col col-md-8">
        <section id="cbServiceAddress" class="row">
          <div class="col-xs-12">
            <h3 >Service Address</h3>
            <span class="addr3">{{addr1}}, {{addr2}}, {{addr3}}</span>          
            <div class="check-wrap">
              <input id="cbMovingToAddress" type="checkbox" name="cbMovingToAddress"/>
              <label for="cbMovingToAddress">I am moving to this address</label>
            </div>
          </div>
        </section>
        <section id="cbCustomerInfo">
          <h3 >Enter Customer Information</h3>
          <div class="row">
            <div class="col-xs-12 col-md-6">
              <label for="cbFirstName" >First Name</label>
              <div class="input-wrap">
                <input id="cbFirstName" name="cbFirstName" type="text" data-rules="txt|req"/>
                <span class="err-msg"></span>
              </div>
            </div>
            <div class="col-xs-12 col-md-6">
              <label for="cbLastName" >Last Name</label>
              <div class="input-wrap">
                <input id="cbLastName" name="cbLastName" type="text" data-rules="txt|req"/>
                <span class="err-msg"></span>
              </div>
            </div>
          </div>
          <div class="row">
            <div class="col-xs-12 col-md-6">
              <label for="cbEmail" >Email</label>
              <div class="input-wrap">
                <input id="cbEmail"  name="cbEmail" type="text" data-rules="email|req"/>
                <span class="err-msg"></span>
              </div>
            </div>
            <div class="col-xs-12 col-md-6">
              <label for="cbPhone" >Phone</label>
              <div class="input-wrap">
                <input id="cbPhone"  name="cbPhone" maxlength="12" onchange="addPhoneNumberDashes(this)" onkeyup="addPhoneNumberDashes(this)" onkeypress="addPhoneNumberDashes(this)"  type="text" data-rules="phone|req"/>
                <span class="err-msg"></span>
              </div>
              <span class="disclaimer">We'll call you at this number to complete your order</span>
            </div>
          </div>
        </section>
        <section id="cbInstallation" class="row">
          <div class="col-xs-12 col-md-6">
            <label for="cbPreferDate" >Preferred Installation Date</label>
            <select id="cbPreferDate" name="cbPreferDate"  data-rules="req">
              <option value="next-week" selected>In the next week</option>
              <option value="two-weeks">In 2 weeks</option>
              <option value="one-month">In 1 month</option>
              <option value="More than a month">More than a month</option>          
            </select>
            <div id="cbSelectOptions"></div>
          </div>
      </section>
      </div>
      <div class="cb-col col-md-4">
        <aside id="cbCart">
          <h2 >Your Cart</h2>
           <span ng-if="getImageExternalId(productData)"><img id="provider_logo" src="/common/logos/{{imageExternalId}}.png"/></span>        
          <div class="cb-prod-info">
               <span>{{productData.name}}</span>
            <span><strong>{{productData.monthlyPrice | currency }}<sup>/mo*</sup></super></strong></span>
          </div>
          <div class="reveal-wrap" aria-role="button">
            <div class="reveal-panel" aria-expanded="false">
              <ul>
                <li class="fa fa-television" ng-if="productData.metadataList.NUM_CHANNELS" ><span>TV - {{productData.metadataList.NUM_CHANNELS}} Channels</span></li>
                <li class="fa fa-wifi" ng-if="productData.metadataList.CONN_SPEED" ><span>Internet - Up to {{productData.metadataList.CONN_SPEED}} Mbps</span></li>
                <!-- <li class="fa fa-phone"><span>Home Phone</span></li> -->
                <li class="fa fa-phone" ng-if="productData.categories.indexOf('Phone') != -1 || productData.categories.indexOf('PHONE') != -1"><span>Home Phone</span></li>
              </ul>
              <div class="additionalInfo"><!-- <span>+</span>--></div>
               <p id="infoTxt">* Installation fees and other fees may apply for equipment or additional features. A credit check and payment information may be required to complete your order.</p>
            </div>
          </div>
        </aside>
        <div id="cbSecureInfo">
          <h4 class="fa fa-lock"><span class="textSafe">Safe and Secure Shopping</span></h4>
          <div>
          <img src="/sites/all/themes/acbrand/img/thawte-icon.jpg" alt="Thawte">
          <img src="/sites/all/themes/acbrand/img/trustwave-icon.png" alt="Secure Trustwave">
          <!-- <img src="/sites/all/themes/acbrand/img/thawte-icon.jpg" alt="Thawte"/>
          <img src="/sites/all/themes/acbrand/img/trustwave-icon.png" alt="Secure Trustwave"/> -->
          </div>
        </div>
      </div>
    </div>
    <section id="cbCTAs" class="row">
      <div class="col-xs-offset-4 col-xs-4">
        <input class="btn btn-primary callProviderContinue" type="submit" value="Submit" />
      </div>
      <div class="col-xs-12">
       <span>Checkout by phone<strong class ="acdc_provider_phone_no"> {{productData.callInOnlyNumber}} </strong></span>
        <a class="cancelOrder" ng-click="removeLineItemFromOrder(callProviderLineItemID,orderId,partnerExternalId)" target="_self">Cancel and continue shopping</a>
      </div>
    </section>  
    <input type="hidden" value="callProviderOrderConfirmation" name="_eventId" id="_eventId" />
   <!--  <input type="hidden" value="cbConsent" name="cbConsentIdname" id="cbConsentIdname" />  -->
    <input type="hidden" value="cbMovingToAddress" name="cbMovingToAddressIdname" id="cbMovingToAddressIdname"/>
    <input type="hidden" value="cbPreferDate" name="cbPreferDateIdname" id="cbPreferDateIdname"/>   
    </form>
    <form method="post" action="{{flowExecutionUrl}}" id="checkoutDispalyForm" name="checkoutDispalyForm">
            <input type="hidden" value="" name="lineItemId" id="hiddenLineItemId">
            <input type="hidden" value="" name="orderId" id="hiddenOrderId" >
            <input type="hidden" value="" name="partnerExternalId" id="hiddenPartnerExternalId" >
            <input type="hidden" value="" name="_eventId" id="checkoutDisplayEventId" >
            <input type="hidden" value="" name="isRemoveLineItem" id="isRemoveLineItem" />
    </form>
  </div>
</div>