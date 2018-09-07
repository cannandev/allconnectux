    <div class="modal fade" tabindex="-1" role="dialog" id="address-capture">
      <div class="modal-dialog">
        <div class="modal-content">
          <div class="modal-header text-center pd-t-md">
            <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
            <h4 class="modal-title headline-base">Enter Your Address to Continue</h4>
          </div>
          <div class="modal-body pd-t-md">
            <form class="address-capture-form">
              <div class="row">
                <div class="form-group col col-md-6 col-xs-12">
                  <label for="street1">Street Address</label>
                  <input id="street1" class="form-control" type="text" onkeyup="return ExpressEntry()">
                </div>
                <div class="form-group col col-md-3 col-xs-6">
                  <label for="aptCondo">Apt</label>
                  <input id="aptCondo" class="form-control" type="text">
                  <span class="form-hint">(if applicable)</span>
                </div>
                <div class="form-group col col-md-3 col-xs-6">
                  <label for="cityStateZip">Zip Code</label>
                  <input id="cityStateZip" class="form-control" type="text">
                  <input id="filter-data" type="hidden" value="">
                </div>             
              </div>    
            </form>
          </div>
          <div class="modal-footer pd-b-lg">
            <button type="submit" class="data-address-submit btn btn-primary">Continue</button>
          </div>
        </div><!-- /.modal-content -->
      </div><!-- /.modal-dialog -->
    </div><!-- /.modal -->