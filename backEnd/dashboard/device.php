<?php
include('../config/db.php');
$kDevice = $link -> query("SELECT * FROM tbl_device;");
 ?>
<div class='container'>
<div class='mb-3'>
<div class="card">
  <div class="card-body">
<h3>Daftar Device</h3>
<div style="margin-bottom:10px;">
  <button class="btn btn-primary" id='btnTambah'>Tambah Device</button>
</div>
<table class="table table-bordered table-responsive" id='table_id'>
<tr>
  <th>Device</th>
  <th>Deksripsi</th>
  <th>Lokasi</th>
  <th>Sedang dipakai</th>
  <th>Aksi</th>
</tr>
<?php
$no = 1;
while($fDev = $kDevice -> fetch_assoc()){
  $idDevice = $fDev['id_device'];
  $capt = $fDev['caption'];
  $deksripsi = $fDev['deksripsi'];
  $lokasi = $fDev['lokasi'];

  echo "
  <tr>
    <td><b>$capt</b><br/>$idDevice</td>
    <td>$deksripsi</td>
    <td>$lokasi</td>
    <td>-</td>
    <td><button class=\"btn btn-primary\">Edit</button></td>
  </tr>
  ";
  $no++;
}
 ?>


</table>
</div>
</div>
</div>
</div>
<script>
$(document).ready(function(){
  let loading = "<i class='fa fa-spin fa-refresh'></i>";

  $('#btnTambah').click(function(){
    $('#conUtama').html(" Memuat halaman ...");
    $('#conUtama').load('tambahDevice.php');
  });

});
</script>
