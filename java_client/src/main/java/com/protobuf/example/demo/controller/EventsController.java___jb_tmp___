package com.protobuf.example.demo.controller;

import com.protobuf.example.demo.dto.EventDto;
import com.protobuf.example.demo.exception.BusinessException;
import com.protobuf.example.demo.service.NotificationService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

/**
 * @author valentin.ihut
 * @since 1.0.0
 */
@RestController
public class EventsController {

  private NotificationService notificationService;

  public EventsController(NotificationService notificationService) {
    this.notificationService = notificationService;
  }

  @PostMapping(value = "/events")
  public ResponseEntity postEvent(@RequestBody EventDto eventDto) throws BusinessException {
    notificationService.sendSocketMessageToServer(eventDto);
    return ResponseEntity.ok().build();
  }

}
