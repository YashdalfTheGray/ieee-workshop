import { Injectable } from 'angular2/core';
import { Http, Response, RequestOptions, Headers } from 'angular2/http';
import { Observable } from '../node_modules/rxjs/Rx.d.ts';

@Injectable()
export class ParticleService {
    constructor(public http: Http) { }

    getDevices(): Observable<Response> {
        var reqOptions = new RequestOptions({
            headers: new Headers({
                'Authorization': 'Bearer ieee-sac-2016-workshop'
            })
        });
        return this.http.get('https://particle-proxy.herokuapp.com/api/v1/devices', reqOptions);
    }

    getVariable(deviceId: string, variableName: string): Observable<Response> {
        var reqOptions = new RequestOptions({
            headers: new Headers({
                'Authorization': 'Bearer ieee-sac-2016-workshop'
            })
        });
        return this.http.get(
            'https://particle-proxy.herokuapp.com/api/v1/devices/' + deviceId + '/' + variableName,
            reqOptions
        );
    }
}
