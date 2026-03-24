package com.demo.entity;


import jakarta.persistence.*;
import lombok.Data;

@Entity
@Data
@Table(name = "sensor_data")
public class SensorData {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(name = "sensor_id")
    private String sensorId;

    private double temperature;
    private int humidity;
    private long timestamp;


}

/*
*  工业级entity注解方法
* @Data
@Builder
@NoArgsConstructor
@AllArgsConstructor

* */