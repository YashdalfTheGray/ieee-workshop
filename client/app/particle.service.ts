import { Injectable } from 'angular2/core';
import { Http, Response } from 'angular2/http';

@Injectable()
export class ParticleService {
    constructor(public http: Http) { }

    getDevices(authToken) {

    }

    getVariable(authToken, deviceId, variable) {

    }
}
