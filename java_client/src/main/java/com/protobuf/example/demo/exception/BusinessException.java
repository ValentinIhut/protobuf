package com.protobuf.example.demo.exception;

public class BusinessException extends Exception {

    private static final long serialVersionUID = 5663692599805797427L;

    public BusinessException(String message) {
        super(message);
    }

}
