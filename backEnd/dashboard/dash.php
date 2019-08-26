<?php

include('../config/db.php');

?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <title>Dasboard Utama - BigOt</title>
    <meta content='width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no' name='viewport'/>
    <!-- Bootstrap 3.3.2 -->
    <link href="../heleh/bootstrap/css/bootstrap.min.css" rel="stylesheet" type="text/css" />
    <!-- Font Awesome Icons -->
    <link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css" rel="stylesheet" type="text/css" />
    <!-- Ionicons -->

    <!-- Theme style -->
    <link href="../heleh/dist/css/AdminLTE.min.css" rel="stylesheet" type="text/css" />
    <!-- AdminLTE Skins. Choose a skin from the css/skins
         folder instead of downloading all of them to reduce the load. -->
    <link href="../heleh/dist/css/skins/_all-skins.min.css" rel="stylesheet" type="text/css" />
    <link rel="stylesheet" type="text/css" href="https://cdn.datatables.net/1.10.19/css/jquery.dataTables.css">
<!-- jQuery 2.1.3 -->
    <script src="../heleh/plugins/jQuery/jquery-2.2.3.min.js"></script>
    <script src="../heleh/bootstrap/js/bootstrap.min.js" type="text/javascript"></script>
<script src="https://adminlte.io/themes/AdminLTE/bower_components/datatables.net/js/jquery.dataTables.min.js"></script>
<script src="https://adminlte.io/themes/AdminLTE/bower_components/datatables.net-bs/js/dataTables.bootstrap.min.js"></script>

    <!-- Bootstrap 3.3.2 JS -->

    <!-- SlimScroll -->


    <!-- FastClick -->
    <script src='../heleh/plugins/fastclick/fastclick.min.js'></script>
    <!-- AdminLTE App -->
    <script src="../heleh/dist/js/app.min.js" type="text/javascript"></script>
    <!-- AdminLTE for demo purposes -->
    <script src="../heleh/dist/js/demo.js" type="text/javascript"></script>
    <script type="text/javascript" src="../heleh/dasbor.js"></script>
    <link href="https://cdnjs.cloudflare.com/ajax/libs/select2/4.0.6-rc.0/css/select2.min.css" rel="stylesheet" />
    <script src="https://cdnjs.cloudflare.com/ajax/libs/select2/4.0.6-rc.0/js/select2.min.js"></script>
    <script src="https://unpkg.com/axios/dist/axios.min.js"></script>
    <!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
        <script src="../../https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script>
        <script src="../../https://oss.maxcdn.com/libs/respond.js/1.3.0/respond.min.js"></script>
    <![endif]-->
  </head>
  <!-- ADD THE CLASS layout-top-nav TO REMOVE THE SIDEBAR. -->
  <body class="skin-blue layout-top-nav">
    <div class="wrapper">

      <header class="main-header">
        <nav class="navbar navbar-static-top">
          <div class="container-fluid">
          <div class="navbar-header">
            <a href="#" class="navbar-brand"><b>Big</b>Ot</a>

          </div>

          <!-- Collect the nav links, forms, and other content for toggling -->
          <div class="collapse navbar-collapse" id="navbar-collapse">
            <ul class="nav navbar-nav">
              <li><a href="#!" id="tblBeranda">Beranda Utama<span class="sr-only">(current)</span></a></li>
              <li class="dropdown">
                <a href="#!" class="dropdown-toggle" data-toggle="dropdown">Master Data<span class="caret"></span></a>
                <ul class="dropdown-menu" role="menu">
                  <li><a href="#!" id="btnDevice">Device</a></li>
                   <li><a href="#!" id="btnPengguna">Pengguna</a></li>
                  </ul>
              </li>

               <li><a href="#!" id="btnMonitoring">Monitoring</a></li>
               <li><a href="#!" id="btnHistory">History</a></li>
               <li><a href="#!" id="btnHistory">Kunci Akses API</a></li>
            </ul>
            <ul class="nav navbar-nav navbar-right">
              <li class="dropdown">
                <a href="#" class="dropdown-toggle" data-toggle="dropdown">Administrator<span class="caret"></span></a>
                <ul class="dropdown-menu" role="menu">

                  <li><a href="logOut.php" id="tblLogOut">Logout</a></li>
                </ul>
              </li>
            </ul>
          </div><!-- /.navbar-collapse -->
          </div><!-- /.container-fluid -->
        </nav>
      </header>
      <!-- Full Width Column -->
      <div class="content-wrapper">
        <div class="container-fluid">
          <!-- Content Header (Page header) -->
          <section class="content-header" id="con_pag">
            <h1 id="capMenu">Beranda</h1>
            <small>Administrator page</small>
          </section>
<br/>
         <div class="box box-solid box-info">
        <div class="box-header">
          <h3 class="box-title" id="capMenu">Statistik Utama</h3>
        </div><!-- /.box-header -->
        <div class="box-body" id="conUtama">

        	</div><!-- /.box-body -->
      </div>



        </div><!-- /.container -->
      </div><!-- /.content-wrapper -->
      <footer class="main-footer">
        <div class="container-fluid">
          <div class="pull-right hidden-xs">

          </div>
          <strong>BigOt</strong> - Dilo Hackathon Festival 2019
        </div><!-- /.container -->
      </footer>
    </div><!-- ./wrapper -->


  </body>
</html>
