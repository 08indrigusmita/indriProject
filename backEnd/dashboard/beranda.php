<?php
$curl = curl_init();
curl_setopt_array($curl, array(
  CURLOPT_URL => "https://platform.antares.id:8443/~/antares-cse/antares-id/macetdimana/temperaturDevice/la",
  CURLOPT_RETURNTRANSFER => true,
  CURLOPT_ENCODING => "",
  CURLOPT_MAXREDIRS => 10,
  CURLOPT_TIMEOUT => 30,
  CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
  CURLOPT_CUSTOMREQUEST => "GET",
  CURLOPT_HTTPHEADER => array(
  'X-M2M-Origin: 312081717901542f:9dd6fc85a09c44df',
  'Content-Type : application/json;ty=4',
  'Accept : application/json'),
));

$response = curl_exec($curl);
$err = curl_error($curl);
curl_close($curl);


 ?>
<div class='container'>
<div class='mb-3'>
<div class="card">
  <div class="card-body">
<h3>Realtime Device</h3>
<hr/>
<?php

 function Parse ($url) {
        $fileContents= $url;
        $fileContents = str_replace(array("\n", "\r", "\t"), '', $fileContents);
        $fileContents = trim(str_replace('"', "'", $fileContents));
        $simpleXml = simplexml_load_string($fileContents);
        $json = json_encode($simpleXml);

        return $json;
    }

if($err){
  echo "Curl error ". $err;
}else{
  $pecahLagi = explode(' ', $response);
  $pecahApa = json_decode($pecahLagi[32]);

  //echo $pecahApa->temperature;
   //var_dump($pecahLagi[32]);
}


 ?>
<div id='divArray' style='color:white;'><?=$pecahLagi[32]; ?>
</div>
<div id='suhuDiv' style='font-size:40px;'></div><br/>
<div id='humi' style='font-size:40px;'></div>
<div id='kendaraan'  style='font-size:40px;'>
<?php
// include('ambilJumlahKendaraan.php');
 ?>
</div>
</div>
</div>
</div>
</div>
<script>
$(document).ready(function(){
 let bahan = $('#divArray').html();
 let saring1 = bahan.replace("<con>","");
 let saring2 = saring1.replace("</con>","");
 let obj = JSON.parse(saring2);

 $('#suhuDiv').html("Kelembapan : " + obj.humidity);
  $('#humi').html("Suhu : " + obj.temperature);
  //$('#kendaraan').html("Jumlah kendaraan : " + kendaraan.jumlah_kendaraan);
});
</script>
