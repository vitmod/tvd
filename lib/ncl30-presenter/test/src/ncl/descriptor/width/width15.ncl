<?xml version="1.0" encoding="ISO-8859-1"?>
<ncl id="test_descriptor_width_15" xmlns="http://www.ncl.org.br/NCL3.0/EDTVProfile">
	<head>
		<regionBase>
			<region id="reg" value="25%"/>
		</regionBase>
		<descriptorBase>
			<descriptor id="desc" region="reg">
			      <descriptorParam name="width" value="50%"/>
			</descriptor>
		</descriptorBase>
	</head>
	<body>
		<port id="port" component="image" />
		<media id="image" src="../../../../images/blue.jpg" descriptor="desc" />
	</body>
</ncl>
