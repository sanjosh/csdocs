
```
select type, client_ip, domain_name, user_agent, time, request_url, request_verb, elb_status_code, target_status_code, actions_executed, classification_reason, error_reason, target_processing_time from alblogs where time > 'YYYY-MM-DDT00:00:00Z' and time < 'YYYY-MM-DDT00:00:00Z' order by time desc
```
