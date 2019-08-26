<?php
include('config/db.php');
$username = $_POST['username'];
$password = $_POST['password'];
$password = md5($password);

//cek data
$kUser = $link -> query("SELECT id FROM tbl_user WHERE username='$username' AND password='$password' LIMIT 0,1; ");
$jlhUser = mysqli_num_rows($kUser);

if($jlhUser < 1){
  $data['status'] ='fail_password';
}else{
  $data['status'] ='success';
}



echo json_encode($data);
?>
