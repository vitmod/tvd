<?xml version="1.0" encoding="ISO-8859-1"?>
<ncl id="test_descriptor_top_1" xmlns="http://www.ncl.org.br/NCL3.0/EDTVProfile">
	<head>
		<regionBase>
			<region id="reg" />
		</regionBase>
		<descriptorBase>
			<descriptor id="desc" region="reg" >
				<descriptorParam name="top" value="50%" />
			</descriptor>
		</descriptorBase>

	</head>
	<body>
		<port id="port" component="image" />
		<media id="image" src="../../../../images/blue.jpg" descriptor="desc" />
	</body>
</ncl>