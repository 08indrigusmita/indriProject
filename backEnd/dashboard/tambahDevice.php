<div class='container'>
<div class='mb-3'>
<div class="card">
  <div class="card-body">
<h4>Form tambah device</h4>
<hr/>
<div class="col-md-4">
<div class="form-group">
                  <label for="exampleInputEmail1">Id Device</label>
                  <input type="text" class="form-control" id="txtIdDevice" placeholder="Id Device">
</div>
<div class="form-group">
                  <label for="exampleInputEmail1">Nama Device</label>
                  <input type="text" class="form-control" id="txtNamaDevice" placeholder="Nama Device">
</div>
<div class="form-group">
                  <label for="exampleInputEmail1">Deksripsi</label>
                  <input type="text" class="form-control" id="txtDeksripsiDevice" placeholder="Deksripsi device">
</div>
<button id='btnTambah' class="btn btn-primary">Tambah</tambah>
</div>
</div>
</div>
</div>
</div>
<script>
$(document).ready(function(){
  	var loading = "<i class='fa fa-spin fa-refresh'></i>";
  $('#btnTambah').click(function(){
    let idDevice = $('#txtIdDevice').val();
    let namaDevice = $('#txtNamaDevice').val();
    let deksripsi = $('#txtDeksripsiDevice').val();
    $.post('prosesTambahDevice.php',{'idDevice':idDevice,'namaDevice':namaDevice,'deksripsi':deksripsi},function(){
      $('#conUtama').html(loading + " Memuat halaman ...");
      $('#conUtama').load('device.php');
    });
  });
});
</script>
