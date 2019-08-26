<?php
$curl = curl_init();
curl_setopt_array($curl, array(
  CURLOPT_URL => "https://platform.antares.id:8443/~/antares-cse/antares-id/macetdimana/counterUtama/la",
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

if($err){
  echo "Curl error ". $err;
}else{
  $pecahLagi = explode(' ', $response);
  $pecahApa = json_decode($pecahLagi[32]);

  //echo $pecahApa->temperature;
   //var_dump($pecahLagi[32]);
}
echo "Jumlah kendaraan : ".$response;
 ?>
