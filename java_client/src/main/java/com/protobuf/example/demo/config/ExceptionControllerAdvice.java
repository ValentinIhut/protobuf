package com.protobuf.example.demo.config;

import com.protobuf.example.demo.exception.BusinessException;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;
import org.springframework.web.context.request.WebRequest;

/**
 * @author valentin.ihut
 * @since 1.0.0
 */
@RestControllerAdvice
public class ExceptionControllerAdvice {

  @ExceptionHandler({BusinessException.class})
  protected ResponseEntity<Object> handleConflict(BusinessException e, WebRequest request) {
    return new ResponseEntity<>(e, null, HttpStatus.INTERNAL_SERVER_ERROR);
  }
}