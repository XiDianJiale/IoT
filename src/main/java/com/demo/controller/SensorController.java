package com.demo.controller;


import com.demo.entity.SensorData;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("api/sensor")
public class SensorController {

    private static final Logger log = LoggerFactory.getLogger(SensorController.class);

    @Autowired
    private com.demo.repo.SensorDataRepository repo;


    @PostMapping("/data")
    public String receiveData(@RequestBody SensorData data){
        log.info("接收到来自 {} 的数据: 温度={}℃, 湿度={}%",
                data.getSensorId(), data.getTemperature(), data.getHumidity());

        repo.save(data);

        return "{\"status\": \"success\", \"message\": \"Data saved to H2 DB\"}";


    }

}
